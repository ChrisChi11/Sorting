#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "MergeSort.h"

void MergeSort_Sort(int *arr, int length)
{
	MergeSort_Split(arr, length);
}

void MergeSort_Split(int *arr, int ElementCnt)
{
	//printf("start = %d, end = %d\n", start, end);
	if (ElementCnt < 2)
		return;

	int mid = ElementCnt / 2;
	int *LBuf = NULL;
	int *RBuf = NULL;

	LBuf = (int*)malloc(mid * sizeof(int));
	RBuf = (int*)malloc((ElementCnt - mid) * sizeof(int));

	for (int i = 0; i<mid; i++)
		LBuf[i] = *(arr + i);
	for (int i = mid; i<ElementCnt; i++)
		RBuf[i - mid] = *(arr + i);

	MergeSort_Split(LBuf, mid);
	MergeSort_Split(RBuf, ElementCnt - mid);

	MergeSort_Merge(arr, LBuf, RBuf, mid, ElementCnt - mid);
	free(LBuf);
	free(RBuf);
}

void MergeSort_Merge(int *arr, int *LBuf, int *RBuf, int LCnt, int RCnt)
{
	int s32LeftIdx = 0, s32RightIdx = 0;
	int i = 0;

	while (s32LeftIdx<LCnt && s32RightIdx<RCnt)
	{
		if (LBuf[s32LeftIdx] < RBuf[s32RightIdx])
		{
			*(arr + i) = LBuf[s32LeftIdx];
			i++;
			s32LeftIdx++;
		}
		else
		{
			*(arr + i) = RBuf[s32RightIdx];
			i++;
			s32RightIdx++;
		}

	}

	while (s32LeftIdx<LCnt)
		*(arr + (i++)) = LBuf[s32LeftIdx++];
	while (s32RightIdx<RCnt)
		*(arr + (i++)) = RBuf[s32RightIdx++];
}