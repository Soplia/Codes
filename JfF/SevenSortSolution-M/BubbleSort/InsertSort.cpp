#include "InsertSort.h"
#include "Tool.h"

void InsertSort1(int * a, int size)
{
	int temp , j;
	for (int i = 1; i < size; i++)
	{
		temp = a[i];
		for ( j = i - 1; j >= 0 && a[j] > temp; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
}

void InsertSort2(int * a, int size)
{
	for (int i = 1; i < size; i++)
		for (int j = 0; j >= 0 && a[j] > a[j + 1]; j--)
			Swap(a[j], a[j + 1]);
}
