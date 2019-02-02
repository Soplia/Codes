/*
  	Subject:产值过多少年翻一番 
	ID:6.7
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 09:39
	EndTime:
*/
#include <stdio.h>
#include <math.h>
#define EPS 1e-1

int main()
{
	float rate,tcap=100,cap=100;
	scanf("%f",&rate);
	int year;
	
	for(year=0;cap<=2*tcap;year++)
		cap=cap*(1+rate);
		
	printf("%d\n",year);
	return 0;	
} 
