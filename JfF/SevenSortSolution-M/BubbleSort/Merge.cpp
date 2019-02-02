#include "Merge.h"

void MergeMatrix(int * a, int left, int mid, int right, int * temp)
{
	int i = left, j = mid + 1;
	int pos = 0;
	while (i <= mid && j <= right)
		if (a[i] < a[j])
			temp[pos++] = a[i++];
		else
			temp[pos++] = a[j++];

	while (j <= right)
		temp[pos++] = a[j++];

	while (i <= mid)
		temp[pos++] = a[i++];

	//至关重要的一步
	for (int k = 0; k < pos; k++)
		a[left + k] = temp[k];
}

void MergeSort(int * a, int left, int right, int * temp)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid, temp);
		MergeSort(a, mid + 1, right, temp);
		MergeMatrix(a, left, mid, right, temp);
	}
}
