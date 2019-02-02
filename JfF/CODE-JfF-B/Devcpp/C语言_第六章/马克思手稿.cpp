/*
  	Subject:马克思手稿 
	ID:6.14
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 10:50
	EndTime:31/01/17 10:53
*/
#include <stdio.h>

int main()
{
	for(int i=0;i<=17;i++)
		for(int j=0;j<=25;j++)
		{
			int temp=30-i-j;
			if(i*3+j*2+temp==50)
				printf("%d+%d+%d\n",i,j,temp);
		}
	return 0;
}
