/*
	Subject: QuickSort 
	Compiler:Devcpp
	Description: 写QS是可以使用已有的函数库中的函数，但是也要掌握QS的思想、代码； 
				以下是正确的QS代码； 
	Id:2-1-4 
	Author:JiaruiXie 
	Date: 04/01/17 12:52
*/
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int ,int ,int *);
int partition(int ,int ,int *);

int main()
{
	int size;
	//printf("输入数组大小：\n");
	scanf("%d",&size);
	int *p=(int *)malloc(size*sizeof(int));
	//printf("输入数据：\n");
	for(int i=0;i<size;i++)
		scanf("%d",p+i);
	
	QuickSort(0,size-1,p);
	
	for(int i=0;i<size;i++)
		printf("%2d",p[i]);
	return 0;
}

void QuickSort(int low,int high,int *a)
{
	//限定条件要有 
	if(low<high) 
	{
		int pivot=partition(low,high,a);
		//printf("pivot=%d\n",pivot);
		QuickSort(low,pivot-1,a);
		QuickSort(pivot+1,high,a);
	}
}

int partition(int low,int high,int *a)
{
	int pivot=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>pivot)
			high--;
		a[low]=a[high];
		while(low<high&&a[low]<pivot)
			low++;
		a[high]=a[low];
	}
	//在每一趟的最后进行置换 
	a[low]=pivot;
	return low;
}



















