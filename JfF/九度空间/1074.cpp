/*
Subject:对称平方数 
ID:1074
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 09:15
Result:Accepted
EndTime:20/03/17 09:20
*/

#include <stdio.h>
#include <string.h>
#define N 10

char aa[N];

int main()
{
	for(int i=0;i<256;i++)
	{
		int flag=1;
		int temp=i*i;
		sprintf(aa,"%d",temp);
		for(int k=0,j=strlen(aa)-1;k<j;k++,j--)
			if(aa[k]!=aa[j])
			{
				flag=0;
				break;
			}
		if(flag)
			printf("%d\n",i);
	}
	return 0;
}

/*
InputData:
无任何输入数据
OutputData:
输出具有题目要求的性质的数。如果输出数据不止一组，各组数据之间以回车隔开。
*/

