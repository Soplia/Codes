/*
  	Subject:求所有的水仙花数 
	ID:6.10
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 10:21
	EndTime:31/01/17 10:31
*/
#include <stdio.h>

int main()
{
	for(int i=100;i<=999;i++)
	{
		int temp=i;
		int a=temp%10;
		temp/=10;
		int b=temp%10;
		temp/=10;
		if(temp*temp*temp+b*b*b+a*a*a==i)
			printf("%d\n",i);
	}
	return 0;
}
