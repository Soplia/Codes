/*
Subject:2009_2
ID:2009_2
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 22:12
Result:Accepted
EndTime:06/02/17 22:14
*/
#include <stdio.h>

int judge(int x)
{
	if(x<=0||x==1)
		return 0;
	else
		for(int i=2;i<x;i++)
			if(x%i==0)
				return 0;
	return 1;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%s\n",judge(n)?"yes":"no");
	}
	return 0;
}
/*
InputData:
13
OutputData:
yes
*/

