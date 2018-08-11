#ifndef __SORT_ALGORITHM_H__
#define __SORT_ALGORITHM_H__

#include <vector>

using  std::vector;

//冒泡排序
void bubbleSort( vector<int>& v );

//选择排序
void selectSort( vector<int>& v );

//插入排序
void insertSort(vector<int>& v);

//计数排序
void countSort( vector<int>&N );

void mergeArray( vector<int>& v, int start, int mid, int end, vector<int>& temp );
void mergeSort( vector<int>& v, int start, int end, vector<int>& temp );
void mergeSort( vector<int>& v );

//快速排序
void quickSort( vector<int>& v );
void quickSort( vector<int>& v, int start, int end );

#endif // !__SORT_ALGORITHM_H__

