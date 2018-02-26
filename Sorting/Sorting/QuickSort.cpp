#include "QuickSort.h"

void QuickSort_Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort_MainProc(int *arr, int start, int end)
{
	if (start >= end)
		return;

	int left = start, right = end - 1;
	int pivot = *(arr + end);

	while (left < right)
	{
		while ((*(arr + left) < pivot) && (left < right))
			left++;
		while ((*(arr + right) >= pivot) && (right > left))
			right--;

		QuickSort_Swap((arr + left), (arr + right));
	}

	if (*(arr + left) > pivot)
		QuickSort_Swap((arr + left), (arr + end));
	else
		left++;

	if (left)
		QuickSort_MainProc(arr, start, left - 1);

	QuickSort_MainProc(arr, left + 1, end);
}

void QuickSort_Sort(int *arr, int length)
{
	QuickSort_MainProc(arr, 0, length - 1);
}