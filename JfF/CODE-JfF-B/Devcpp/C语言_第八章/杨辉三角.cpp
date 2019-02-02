/*
Subject:Ñî»ÔÈý½Ç 
ID:8.12
Complier:Devcpp
Author:JiaruiXie
StartTime:23/01/17 21:27
EndTime:23/01/17 21:36
*/
#include <stdio.h>
#define N 20

int a[N][N];

void print(int row)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<=i;j++)
			printf("%-4d",a[i][j]);
		printf("\n");
	}
}

int main()
{
	
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			a[i][j]=1;
			
	for(int i=0;i<N;i++)
		a[i][0]=1;
		
	int row=8;
	
	for(int i=2;i<row;i++)
	{
		for(int j=1;j<i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	
	print(row);
	return 0;	
} 
