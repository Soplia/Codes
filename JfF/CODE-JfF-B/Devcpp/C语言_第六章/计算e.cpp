/*
  	Subject:计算e _不知道哪里错了 
	ID:6.9
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 09:55
	EndTime:31/01/17 10:20
*/
#include <stdio.h>
#define EPS 1e-5

int main()
{
	float sum=0;
	float term=1;
	int count=1;
	
	while(1/term>=EPS)
	{
		sum+=1/term;
		count++;
		term*=count;
		//rintf("%.2f\n",term);
	}
	
	printf("%.3f\n",sum);
	return 0;
}



