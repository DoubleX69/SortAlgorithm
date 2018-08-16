
#include "Test.h"
#include "SortAlgorithm.h"

#include <time.h>
#include <algorithm>

Test::Test( )
{
}

Test::~Test( )
{
}


vector<int> Test::genTestVector( int size )
{
    vector<int> v( size, 0 );

    srand( ( unsigned int )time( NULL ) );

    for ( int i = 0; i < size; ++i )
    {
        int val = rand( ) % 200 - 100;
        v[i] = val;
    }

    return  v;
}

int Test::genRndNumber( int a, int b )
{
    srand( ( unsigned int )time( NULL ) );
    int val = rand( ) % (b - a) + a;
    return val;
}


void Test::showVector( const vector<int>& v )
{
    for ( size_t i = 0; i < v.size( ); i++ )
    {
        cout << v.at( i ) << " , ";
    }
    cout << endl;
}

bool Test::rndTest( SORT_FUNC sort_func  )
{
    bool ret = true;
    for ( int i = 0; i < 100; ++i )
    {
        int size = genRndNumber( 2, 100 );
        vector<int> v = genTestVector( size );
        vector<int> r = v;

       // showVector( v );
        // SORT
        sort_func( v );
       // showVector( v );

        if ( !isRight( v, r ) )
        {
            ret = false;
            break;
        }
    }

    return ret;
}

bool Test::isRight( const vector<int>& v, vector<int>& r )
{
    std::sort( r.begin( ), r.end( ) );

    for ( size_t i = 0; i < r.size( ); ++i )
    {
        if ( v[i] != r[i] )
        {

            cout << "Sort Result is : " << endl;
            showVector( v );
            cout << "But Right Result is : " << endl;
            showVector( r );
            return false;
        }
    }
    return true;
}


bool Test::preTest( SORT_FUNC sort_func )
{
    vector<int> v = genTestVector( 20 );
    vector<int> r = v;
    sort_func( v );
    return isRight( v, r );
}


bool Test::test( SORT_FUNC sort_func  )
{
    bool ret = false;
    if ( preTest( sort_func  ) )
    {
        if ( rndTest( sort_func  ) )
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }
    else
    {
        ret = false;
    }
    return ret;
}

bool Test::test( )
{
    bool ret = true;
    for ( auto it = sort_funcs_.begin( ); it != sort_funcs_.end( ); ++it )
    {
        if( test( it->second ) ) 
        {
            cout << it->first << " : PASS " << endl;
            ret = ret & true;
        }
        else
        {
            cout << it->first << " : FAIL " << endl;
            ret = ret & false;
        }     
    }

    return ret;
}

bool Test::add( const string& name, SORT_FUNC sort_func )
{
    sort_funcs_.insert( std::pair<string, SORT_FUNC>( name, sort_func ) );
    return true;
}

const map<string, long>& Test::calcTime( int size )
{
    vector<int>     raw_vec = genTestVector( size );
    vector<int>     test_vec = raw_vec;

    clock_t start_time = 0;
    clock_t end_time  = 0;

    elapsed_times_.clear( );

    for ( auto it = sort_funcs_.begin( ); it != sort_funcs_.end( ); ++it )
    {
        const string name = it->first;
        auto func = it->second;
        test_vec = raw_vec;
        start_time = clock( );
        (*func)(test_vec);
        end_time = clock( );
        elapsed_times_[name] = end_time - start_time;
    }

    return elapsed_times_;
}