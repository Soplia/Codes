/*
Subject:°Ë½øÖÆ 
ID:1194
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 20:11
Result: Accepted
EndTime:20/03/17 20:16
*/

#include <stdio.h>
#define N 100

int arr[N];

int main()
{
	int size,temp;
	while(scanf("%d",&temp)!=EOF)
	{
		size=0;
		do
		{
			arr[size++]=temp%8;
			temp/=8;
		}while(temp);
		
		for(int i=size-1;i>=0;i--)
			printf("%d",arr[i]);
		printf("\n");
	}
	return 0;
}

/*
InputData:
7
8
9
OutputData:
7
10
11
*/

