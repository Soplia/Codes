/*
Subject:‚Ü‚¾‚Ü‚¾A+B 
ID:4.2
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 16:13
EndTime:
*/
#include <stdio.h>
#define N 20

int array[N];

int main()
{
	int m;
	long a,b;
	while(scanf("%d",&m)!=EOF&&m!=0)
	{
		scanf("%ld%ld",&a,&b);
		long temp=a+b;
		int size=0;
		do
		{
			array[size++]=temp%m;
			temp/=m;
		}while(temp);
		for(int i=size-1;i>=0;i--)
			printf("%d",array[i]);
		printf("\n");
	}
	return 0;
}

/*
InputData:
8 1300 48
2 1 7
0
OutputData:
2504
1000
*/

