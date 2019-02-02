/*
	Subject:排版_梯形 
    Compiler:Devcpp
	Description:输入一个高度h，输出上底边为h的梯形。 
	Author:JiaruiXie
	Id:2-4-1
	Date_Begin:07/01/17 10:26
	Date_End:07/01/17 10:31
*/

#include <stdio.h>

int main()
{
	int h;
	while(scanf("%d",&h)!=EOF)
	{
		int size=h*2-1;
		for(int i=1;i<=h;i++)
		{
			for(int k=1;k<=h-i+1;k++)
				printf(" ");
			for(int j=1;j<=h+i-1;j++)
				printf("*");
			printf("\n");
		}
	}
	return 0;
}


