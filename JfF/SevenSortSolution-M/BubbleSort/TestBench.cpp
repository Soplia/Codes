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
	//就是因为这个位置的类型不对，所以在打印的时候才会打印出来奇怪的内容
	printf("%f\n", ((double)(finish - start)) / CLOCKS_PER_SEC);


	free(arr);
	system("pause");

	return 0;
}
