/*
Subject:9.9
ID:9.9
Complier:Devcpp
Author:JiaruiXie
StartTime:10/02/17 10:28
Result:
EndTime:
*/
#include <stdio.h>
#define N 100

int score[N];

int read(int *a)
{
	int i=-1;
	do
	{
		scanf("%d",&a[++i]);
	}while(a[i]>=0);
	
	return i;
}

void print(int *a,int n)
{
	for(int i=0;i<n;i++)
		printf("%3d",a[i]);
	printf("\n");
}

int ascend(int a,int b)
{
	return a<b;
}

int descend(int a,int b)
{
	return a>b;
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void sort(int *a,int n,int (*cmp)(int ,int))
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
			if(!(*cmp)(a[j],a[j+1]))
				swap(a+j,a+j+1);
}

int main()
{
	int n;
	n=read(score);
	print(score,n);
	sort(score,n,ascend);
	print(score,n);
	sort(score,n,descend);
	print(score,n);
	return 0;
}
/*
InputData:
84 83 88 87 61  -1
-1
OutputData:

*/

