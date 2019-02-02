#include "QuickSort.h"

int QuickSort(int * a, int left, int right)
{
	int i = left, j = right;
	int temp = a[i];

	while (i < j)
	{
		while (i < j && a[j] >=  temp)
			j--;
		a[i] = a[j];
		while (i < j && a[i] <= temp)
			i++;
		a[j] = a[i];
	}

	a[i] = temp;
	return i;
}

void QuickSort(int * a, int left, int right, int test)
{
	while (left > right)
	{
		int pivot = QuickSort(a, left, right);
		QuickSort(a, left, pivot - 1, test);
		QuickSort(a, pivot + 1, right, test);
	}
}