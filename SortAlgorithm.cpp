
#include "SortAlgorithm.h"
#include <iostream>
#include <algorithm>

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

//计数排序
//非比较排序，可以突破NlogN的下限
void countSort( vector<int>&v )
{
    int max_val = *max_element( v.begin( ), v.end( ) );
    int min_val = *min_element( v.begin( ), v.end( ) );
    int len = max_val - min_val + 1;

    vector<int> c( len, 0 );
    vector<int> a( v.size( ), 0 );

    for ( int i = 0; i < v.size(); ++i )
    {
        c[v[i] - min_val] ++;
    }

    for ( int i = 1; i < len; ++i )
    {
        c[i] += c[i - 1];
    }

    for ( int i = 0; i < v.size( ); ++i )
    {
        a[--c[v[i] - min_val]] = v[i];
    }

    v = a;
}

void mergeArray( vector<int>& v, int start, int mid, int end, vector<int>& temp )
{
    int start1 = start , end1 = mid;
    int start2 = mid + 1, end2 = end;
    int k = 0;

    while ( start1 <= end1 && start2 <= end2 )
    {
        temp[k++] = (v[start1] < v[start2]) ? v[start1++] : v[start2++];
    }
    while ( start1 <= end1 )
    {
        temp[k++] = v[start1++];
    }
    while ( start2 <= end2 )
    {
        temp[k++] = v[start2++];
    }

    for ( int i = 0; i < k; ++i )
    {
        v[start + i] = temp[i];
    }
}

void mergeSort( vector<int>& v, int start, int end, vector<int>& temp )
{
    if ( start < end )
    {
        int mid = (start + end) / 2;
        mergeSort( v, start, mid , temp );
        mergeSort( v, mid + 1, end, temp );
        mergeArray( v, start, mid, end, temp );
    }
}
void mergeSort( vector<int>& v )
{
    vector<int> temp(  v.size( ) , 0 );
    mergeSort( v, 0, v.size( ) - 1, temp );
}

//快速排序
void quickSort( vector<int>& v )
{
    quickSort( v, 0 , v.size( ) - 1 );
}
void quickSort( vector<int>& v, int start, int end )
{
    if ( start < end )
    {
        int privot = v[start];
        int left = start + 1;
        int right = end;

        while ( left < right )
        {
            while ( v[right] >= privot && left < right )
            {
                right--;
            }

            while ( v[left] < privot && left < right )
            {
                left++;
            }

            std::swap( v[left], v[right] );
        }

        if ( v[right] <= privot )
        {
            std::swap( v[start], v[right] );
        }
        else
        {
            right--;
        }

        quickSort( v, start, right - 1 );
        quickSort( v, right + 1, end );
    }
}

void quickSort2( vector<int>& v )
{
    quickSort2( v, 0, v.size( ) - 1 );
}

//快速排序
//三相切分
void quickSort2( vector<int>& v, int start, int end )
{
    if ( start < end )
    {
        int pivot = v[start];
        int p_idx = start;
        int left = start + 1;
        int right = end;

        while ( left <= right )
        {
            if ( v[left] < pivot )
            {
                std::swap( v[left++], v[p_idx++] );
            }
            else if ( v[left] > pivot )
            {
                std::swap( v[right--], v[left] );
            }
            else
            {
                left++;
            }
        }

        quickSort2( v, start, p_idx - 1 );
        quickSort2( v, p_idx + 1, end );
    }
}