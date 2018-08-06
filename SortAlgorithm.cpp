
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

//插入排序
// 将未排序部分依次插入到以排序部分合适的位置
void insertSort( vector<int>& v )
{
    for ( int i = 1; i < v.size() ; i++ )
    {
        int j = i;
        int temp = v[i];
        for ( j = i; j > 0 && v[j - 1] > temp; --j )
        {
            v[j] = v[j - 1];
        }
        v[j] = temp;
    }
}