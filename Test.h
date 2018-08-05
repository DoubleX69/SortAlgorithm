#ifndef _TEST_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::map;
using std::string;
using std::cout;
using std::endl;

class Test
{
private:
    typedef void( *SORT_FUNC )(vector<int> &v);

public:
    Test( );
    ~Test( );


    bool add( const string& name , SORT_FUNC sort_func );
    bool test( SORT_FUNC sort_func );
    bool test( );

private:
    vector<int> genTestVector( int size );
    int genRndNumber( int a, int b );
    bool rndTest( SORT_FUNC sort_func );
    void showVector( const vector<int>& v );
    bool isRight( const vector<int>& v, vector<int>& r );
    bool preTest( SORT_FUNC sort_func );

private:
    map< string , SORT_FUNC>           sort_funcs_;
};



#endif // !_TEST_H__

