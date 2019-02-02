/*
Subject:ÖÀ÷»×Ó 
ID:8.14
Complier:Devcpp
Author:JiaruiXie
StartTime:23/01/17 21:36
EndTime:23/01/17 21:40
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7

int a[N]={0};

int main()
{
	srand(time(0));
	
	for(int i=0;i<6000;i++)
		a[(rand()%6+1)]++;
		
	for(int i=1;i<=6;i++)
		printf("%-6.2f",(float)a[i]/6000);
		
	printf("\n");
	return 0;
}
