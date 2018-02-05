
#ifndef MERGE_SORT_H
#define MERGE_SORT_H
void MergeSort_Sort(int *arr, int length);
void MergeSort_Split(int *arr, int ElementCnt);
void MergeSort_Merge(int *arr, int *LBuf, int *RBuf, int LCnt, int RCnt);
#endif