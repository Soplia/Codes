/*
Subject:9.5
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:10/02/17 11:28
Result:
EndTime:
*/
#include <stdio.h>

float fabs(float x)
{
	return x>0?x:-x;
}

float f1(float a)
{
	return 1+(a*a);
}

float f2(float a)
{
	return a/(1+a*a);
}

float Integral(float (*f)(float),float a,float b)
{
	int n=100;
	float sum=0;
	float start,mid,end=a;
	float step=(b-a)/n;
	while(n--)
	{
		start=end;
		end=end+step;
		mid=(start+end)/2;
		sum+=(*f)(mid)*step;
	}
	return sum;
}

int main()
{
	printf("%.4f\n",Integral(f1,0,1));
	printf("%.4f\n",Integral(f2,0,3));
	return 0;
}
/*
InputData:

OutputData:

*/

