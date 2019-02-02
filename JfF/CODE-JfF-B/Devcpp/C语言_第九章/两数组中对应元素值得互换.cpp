/*
Subject:两数组中对应元素值得互换 
ID:9.2
Complier:Devcpp
Author:JiaruiXie
StartTime:23/01/17 10:36
EndTime:23/01/17 10:46
*/
#include <stdio.h>
#define N 10

void swap(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

int main()
{
	int a[N]={0,1,2,3,4,5,6,7,8,9};
	int b[N]={10,11,12,13,14,15,16,17,18,19};
	for(int i=0;i<N;i++)
		swap(&a[i],&b[i]);
	for(int i=0;i<N;i++)
		printf("%-3d",a[i]);
	printf("\n");
	for(int i=0;i<N;i++)
		printf("%-3d",b[i]);
	printf("\n");
	return 0;
}

























