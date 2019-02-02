/*
  	Subject:海军开幕式 
	ID:6.21
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 11:18
	EndTime:31/01/17 11:27
*/
#include <stdio.h>

int main()
{
	int count=0;
	for(int t=0;t<=150;t++)
	{
		if(t%5==0&&t<=20*5)
		{
			count++;
			continue;
		}
		if(t%6==0&&t<=20*6)
		{
			count++;
			continue;
		}
		if(t%7==0&&t<=20*7)
			count++;	
	} 
	printf("%d\n",count);
	return 0;
} 





