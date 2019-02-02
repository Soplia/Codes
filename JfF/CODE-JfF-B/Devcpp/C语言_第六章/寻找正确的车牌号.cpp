/*
  	Subject:寻找正确的车牌号 
	ID:6.19
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 11:12
	EndTime:31/01/17 11:16
*/
#include <stdio.h>
#include <math.h>

int main()
{
	int aim=0;
	for(int i=1;i<=9;i++)
		for(int j=0;j<=9;j++)
		{
			if(i==j)
				continue;
			aim=i*1000+i*100+j*10+j;
			for(int i=0;i<=100;i++)
				if(i*i==aim)
				{
					printf("%d\n",aim);
					break;
				}
		}
	return 0;
}
