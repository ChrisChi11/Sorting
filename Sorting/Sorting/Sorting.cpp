// QuickSort.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

void QuickSort_Swap(int *a, int *b);
void QuickSort_MainProc(int *arr, int start, int end);
void QuickSort_Sort(int *arr, int length);

void BubbleSort_Sort1(int *arr, int length);
void BubbleSort_Sort2(int *arr, int length);


void MergeSort_Sort(int *arr, int length);
void MergeSort_Split(int *arr, int ElementCnt);
void MergeSort_Merge(int *arr, int *LBuf, int *RBuf, int LCnt, int RCnt);

void QuickSort_Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort_MainProc(int *arr, int start, int end)
{
    if(start >= end)
        return;

    int left = start, right = end - 1;
    int pivot = *(arr+end);

    while(left < right)
    {
        while( (*(arr+left) < pivot) && (left < right) )
            left++;
        while( (*(arr+right) >= pivot) && (right > left) )
            right--;

        QuickSort_Swap( (arr+left), (arr+right) );
    }

    if( *(arr+left) > pivot)
        QuickSort_Swap( (arr+left), (arr+end) );
    else 
        left++;

    if(left)
        QuickSort_MainProc(arr, start, left -1);

    QuickSort_MainProc(arr, left+1, end);
}

void QuickSort_Sort(int *arr, int length)
{
    QuickSort_MainProc(arr, 0, length-1);
}

#define LENGTH      7

int a[LENGTH] = { 5, 6, 0, 19, 23, 8, 11};

int main()
{
    //QuickSort_Sort(a, LENGTH);
    MergeSort_Sort(a, LENGTH);
    for(int i=0; i<LENGTH; i++)
    {
        printf("%d ",*(a+i));
    }

    printf("\n");
    system("PAUSE");
    return 0;
}

void BubbleSort_Sort1(int *arr, int length)
{
    for(int j=0; j<length-1; j++)
    {
        for(int i=j+1; i<length; i++)
        {
            if( *(arr+j) > *(arr+i))
                QuickSort_Swap( (arr+i), (arr+j) );
        }    
    }
}

void BubbleSort_Sort2(int *arr, int length)
{
    bool bSwap = false;

    while(1)
    {        
        for(int i=0; i<length-1; i++)
        {
            if( *(arr+i) > *(arr+i+1) )
            {
                QuickSort_Swap( (arr+i), (arr+i+1) );
                bSwap = true;
            }
        }

        if(!bSwap)
            break;
        else
        {
            bSwap = false;
            length -= 1;
        }
    }
}

void MergeSort_Sort(int *arr, int length)
{
    MergeSort_Split(arr,length);
}

void MergeSort_Split(int *arr, int ElementCnt)
{    
    //printf("start = %d, end = %d\n", start, end);
    if(ElementCnt < 2)
        return;

    int mid = ElementCnt / 2;
    int *LBuf = NULL; 
    int *RBuf = NULL;

    LBuf = (int*)malloc(mid * sizeof(int));
    RBuf = (int*)malloc( (ElementCnt - mid) * sizeof(int) );
    
    for(int i=0; i<mid; i++)
        LBuf[i] = *(arr+i);
    for(int i=mid; i<ElementCnt; i++)
        RBuf[i-mid] = *(arr+i);

    MergeSort_Split(LBuf, mid);
    MergeSort_Split(RBuf, ElementCnt - mid);

    MergeSort_Merge(arr, LBuf, RBuf, mid, ElementCnt - mid);
    free(LBuf);
    free(RBuf);
}

void MergeSort_Merge(int *arr, int *LBuf, int *RBuf, int LCnt, int RCnt)
{
    int s32LeftIdx = 0, s32RightIdx = 0;

    for(int i=0; i<(LCnt+RCnt); i++)
    {
        if( (LBuf[s32LeftIdx] < RBuf[s32RightIdx]) && s32LeftIdx < LCnt)
        {
            *(arr+i) = LBuf[s32LeftIdx];
            s32LeftIdx++;
        }
        else
        {
            *(arr+i) = RBuf[s32RightIdx];
            s32RightIdx++;
        }

    }

}