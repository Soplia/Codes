/*
	Subject:º∆À„sin 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.2.5
	Date_Begin:29/01/17 20:39
	Date_End:
*/
#include <stdio.h>
#include <math.h>
#define EPS 1e-5

int main()
{
	float x;
	scanf("%f",&x);
	float sum=x;
	float term=x;
	int count=1;
	int n=3;
	do
	{
		term=-term*pow(x,2)/(n*(n-1));
		n+=2;
		sum+=term;
		count++;
	}while(abs(term)>EPS);
	
	printf("%.2f_%d\n",sum,count);
	return 0;
}


























