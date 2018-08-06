#include "SortAlgorithm.h"
#include "Test.h"

#include <iostream>


int main( )
{
    Test t;

    t.add( "Bubble Sort", bubbleSort );
    t.add( "Select Sort", selectSort );
    t.add( "Insert Sort", insertSort );

    if ( t.test( ) )
    {
        cout << "**************** Pass!! *******************" << endl;
    }
    else
    {
        cout << "**************** Fail!! ******************" << endl;
    }
    return 0;
}