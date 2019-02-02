/*
Subject:交换数组中最大值与最小值得位置 
ID:10.3
Complier:Devcpp
Author:JiaruiXie
StartTime:23/01/17 10:40
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
	int x,y;
	int min=a[0],max=a[0];
	for(int i=0;i<N;i++)
	{
		if(a[i]>=max)
			x=i;
		if(a[i]<=min)
			y=i;
	}
	swap(&a[x],&a[y]);
	for(int i=0;i<N;i++)
		printf("%3d",a[i]);
	printf("\n");
	return 0;
}


























