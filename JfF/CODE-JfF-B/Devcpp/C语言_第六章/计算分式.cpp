/*
	Subject:º∆À„1-1/2+1/3-1/4+....+1/99-1/100 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.2.4
	Date_Begin:29/01/17 20:21
	Date_End:29/01/17 20:39
*/
#include <stdio.h>
#define EPS 1e-4

int main()
{
	int sign=1;
	float sum=0;
	float term=1;
	while(1/term>EPS)
	{
		sum+=sign/term;
		term++;
		sign=-sign; 
	}
	printf("%.2f\n",sum);
	return 0;	
} 
