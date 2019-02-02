#include "HeapSort.h"
#include "Tool.h"

void MinHeapFixUp1(int * a, int pos)
{
	for (int j = (pos - 1) / 2; j >= 0 && a[pos] > a[j]; pos = j,  j = (pos - 1) / 2)
		Swap(a[pos], a[j]);
}

void MinHeapFixUp2(int * a, int pos)
{
	int root = (pos - 1) / 2;
	int temp = a[pos];
	while (root >= 0)
	{
		if (a[root] <= a[pos])
			break;
		a[pos] = a[root];
		pos = root;
		root = (pos - 1) / 2;
	}
	a[root] = temp;
}

//正好是向上调整的逆过程
void MinHeapFixDown(int * a, int aim, int size)
{
	int temp = a[size];
	int leftC = aim * 2 + 1;
	while (leftC <= size) //不知道这个地方有没有等号
	{
		if (leftC + 1 <= size && a[leftC] < a[leftC + 1])
			leftC++;
		if (temp >= leftC)
			break;
		a[aim] = a[leftC];
		aim = leftC;
		leftC = aim * 2 + 1;
	}
	a[leftC] = temp;
}

void MinHeapAddNode(int * a, int n, int num)
{
	a[n] = num;
	MinHeapFixUp2(a, n);
}

void MinHeapDelNode(int * a, int aim, int size)
{
	Swap(a[0], a[size]);
	MinHeapFixDown(a, 0, size - 1);
}

void MakeMinHeap(int * a, int size)
{
	for (int i = size / 2 - 1; i >= 1; i--)
		MinHeapFixDown(a, i, size);
}

void HeapSort(int * a, int size)
{
	for (int i = size - 1; i >= 1; i--)
	{
		Swap(a[i], a[0]);
		MinHeapFixDown(a, 0, i);
	}
}


