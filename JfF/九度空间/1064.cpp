/*
Subject:反序数 
ID:1064
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 09:04
Result: Accepted
EndTime:20/03/17 09:13
*/

#include <stdio.h> 
#include <string.h>
#define N 10

char aa[N],bb[N];

int main()
{
	int i;
	for(i=1000;i<1112;i++)
	{
		int temp=i*9;
		sprintf(aa,"%d",i);
		sprintf(bb,"%d",temp);
		
		int flag=1;
		for(int k=0,j=3;k<4&&j>=0;k++,j--)
			if(aa[k]!=bb[j])
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
程序无任何输入数据
OutputData:
输出题目要求的四位数，如果结果有多组，则每组结果之间以回车隔开
*/

