/*
  	Subject:ผฆอรอฌมý 
	ID:6.15
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 10:53
	EndTime:31/01/17 10:56
*/
#include <stdio.h>

int main()
{
	for(int i=0;i<=98;i++)
		for(int j=0;j<=98;j++)
			if(i*2+j*4==386&&i+j==98)
				printf("%d+%d\n",i,j);
	
	return 0;
}
