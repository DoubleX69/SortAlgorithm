#include "SortAlgorithm.h"
#include "Test.h"

#include <iostream>


int main( )
{
    Test t;

    t.add( "Bubble Sort", bubbleSort );
    t.add( "Select Sort", selectSort );
    t.add( "Insert Sort", insertSort );
    t.add( "Merge  Sort", mergeSort );
    t.add( "Count  Sort", countSort );
    t.add( "Quick  Sort", quickSort );
    t.add( "Quick  Sort2", quickSort2 );
    t.add( "Heap   Sort", heapSort );

    if ( t.test( ) )
    {
        cout << "**************** Pass!! *******************" << endl;
        map<string, long > elapsed_times = t.calcTime( 10000 );

        for ( auto it = elapsed_times.begin( ); it != elapsed_times.end( ); ++it )
        {
            cout << it->first << " : " << it->second  << endl;
        }
    }
    else
    {
        cout << "**************** Fail!! ******************" << endl;
    }
    return 0;
}