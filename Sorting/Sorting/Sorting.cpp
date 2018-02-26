// QuickSort.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "MergeSort.h"




void BubbleSort_Sort1(int *arr, int length);
void BubbleSort_Sort2(int *arr, int length);



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

