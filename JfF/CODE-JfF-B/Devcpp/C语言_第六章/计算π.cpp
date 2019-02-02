/*
  	Subject:º∆À„¶– 
	ID:6.8
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 09:49
	EndTime:31/01/17 09:54
*/
#include <stdio.h>
#define EPS 1e-4

int main()
{
	float sum=0;
	float term=1;
	int sign=1;
	while(1/term>=EPS)	
	{
		sum+=1*sign/term;
		term+=2;
		sign=-sign;
	}	
	printf("%.3f\n",sum);
	return 0;
} 
