
#include "SortAlgorithm.h"
#include <iostream>

//冒泡排序
//相邻数据两两对比，较大的数据上浮
void bubbleSort( vector<int> & v )
{
    for ( int i = 0; i < v.size( ) - 1; ++i )
    {
        for ( int j = 0; j < v.size() - 1 - i ; ++j )
        {
            if ( v[j] > v[j + 1] )
            {
                std::swap( v[j], v[j + 1 ] );
            }
        }
    }
}

//选择排序
//依次选择未排序部分的最小值，移动到前端
void selectSort( vector<int>& v )
{
    for ( int i = 0; i < v.size( ) - 1; ++i )
    {
        int sel = i;
        for ( int j = i + 1; j < v.size( ); ++j )
        {
            if ( v[j] < v[sel] )
            {
                sel = j;
            }
        }
        std::swap( v[i], v[sel] );
    }
}