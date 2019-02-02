/*
Subject:6.6
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:12/02/17 13:51
Result:
EndTime:
*/
#include <stdio.h>
#define N 0.01875

int main()
{
	float s,e=1000,g=1000;
	for(int i=1;i<=5;i++)
	{
		s=e/(1+12*N);
		e=s+g;
	}
	printf("%.2f\n",s);
	return 0;
}

/*
InputData:

OutputData:

*/

