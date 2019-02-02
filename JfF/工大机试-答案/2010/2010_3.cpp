/*
Subject:2010_3
ID:2010_3
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 21:47
Result:Accepted
EndTime:06/02/17 21:57
*/
#include <stdio.h>
#define N 30

int array[N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)	
	{
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);
		int min=array[0],max=min;
		int minP=0,maxP=minP;
		for(int i=1;i<n;i++)
		{
			if(array[i]>max)
			{
				max=array[i];
				maxP=i;
			}
			if(array[i]<min)
			{
				min=array[i];
				minP=i;
			}
		}
		int temp=array[minP];
		array[minP]=array[maxP];
		array[maxP]=temp;
		for(int i=0;i<n;i++)
			if(i==0)
				printf("%d",array[i]);
			else
				printf(" %d",array[i]);
		printf("\n");
	}
	return 0;	
}
/*
InputData:
2
1 3
OutputData:
3 1
*/

