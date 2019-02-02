#include "SelectSort.h"
#include "Tool.h"

void SelectSort(int * a, int size)
{
	for (int i = 0; i < size; i++)
	{
		int pos = i;
		for (int j = i + 1; j < size; j++)
			if (a[j] < a[i])
				pos = j;
		Swap(a[i], a[pos]);
	}
}
