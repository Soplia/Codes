/*
  	Subject:百钱百鸡 注意应该是300 
	ID:6.16
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 10:58
	EndTime:
*/
#include <stdio.h>

int main()
{
	for(int i=0;i<=20;i++)
		for(int j=0;j<=34;j++)
		{
			int temp=100-i-j;
			if(temp+i*15+j*9==300)
				printf("%d+%d+%d\n",i,j,temp);
		}
		
	return 0;
}
