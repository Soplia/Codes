#include <stdio.h>
#include "BubbleSort.h"
#include <time.h>
#include <stdlib.h>
#include "InsertSort.h"
#include "ShellSort.h"
#include "SelectSort.h"
#include "Merge.h"
#include "QuickSort.h"
#include "HeapSort.h"

int main()
{
	clock_t start, finish;

	int size = 10000;
	int *arr = (int *) malloc(sizeof(int) * size);
	int * temp = (int *) malloc(sizeof(int) * size);
	ReadFile(arr);

	start = clock();
	//QuickSort(arr, 0, size - 1, size);
	MakeMinHeap(arr, size);
	HeapSort(arr, size);

	finish = clock();
	DisMatrix(arr, size);
	//������Ϊ���λ�õ����Ͳ��ԣ������ڴ�ӡ��ʱ��Ż��ӡ������ֵ�����
	printf("%f\n", ((double)(finish - start)) / CLOCKS_PER_SEC);


	free(arr);
	system("pause");

	return 0;
}
