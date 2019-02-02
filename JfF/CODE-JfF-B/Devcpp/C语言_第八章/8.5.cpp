/*
Subject:
ID:8.5
Complier:Devcpp
Author:JiaruiXie
StartTime:23/01/17 21:04
EndTime:23/01/17 21:26
*/
#include <stdio.h>
#define N 20

int main()
{
	float a[N];
	int count=0;
	float avg=0;
	do
	{
		scanf("%f",&a[count]);
	}while(a[count++]>=0);
	
	if(count==1)
		printf("%.2f\n",avg);
	else
	{
		for(int i=0;i<count;i++)
			avg+=a[i];
		printf("%.2f\n",avg/(count-1));
	}
	
	return 0;
}


























