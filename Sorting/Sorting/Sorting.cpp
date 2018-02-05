// QuickSort.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "MergeSort.h"


void QuickSort_Swap(int *a, int *b);
void QuickSort_MainProc(int *arr, int start, int end);
void QuickSort_Sort(int *arr, int length);

void BubbleSort_Sort1(int *arr, int length);
void BubbleSort_Sort2(int *arr, int length);

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

#define LENGTH      8
int a[LENGTH] = {1,53,2,3,5,7,8,6};

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

