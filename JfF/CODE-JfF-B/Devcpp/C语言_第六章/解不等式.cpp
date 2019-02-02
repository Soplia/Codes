/*
  	Subject:解不等式 
	ID:6.11
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 10:33
	EndTime:31/01/17 10:40
*/
#include <stdio.h>
#define N 30

int array[N+1];

int getF(int a)
{
	int sum=1;
	for(int i=1;i<=a;i++)
		sum*=i;
	return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=N;i++)
		array[i]=getF(i);
	
	int sum=1;
	for(int i=1;sum<n;i++)
	{
		printf("%d\n",i);
		sum+=array[i];
	}
	return 0;
}
