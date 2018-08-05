#include "SortAlgorithm.h"
#include "Test.h"

#include <iostream>


int main( )
{
    Test t;

    t.add( "Bubble Sort", bubbleSort );


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