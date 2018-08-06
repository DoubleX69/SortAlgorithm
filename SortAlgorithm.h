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

void mergeArray( vector<int>& v, int start, int mid, int end, vector<int>& temp );
void mergeSort( vector<int>& v, int start, int end, vector<int>& temp );
void mergeSort( vector<int>& v );

#endif // !__SORT_ALGORITHM_H__

