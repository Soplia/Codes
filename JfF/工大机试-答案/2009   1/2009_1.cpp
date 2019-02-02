/*
Subject:2009_1
ID:2009_1
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 22:08
Result:Accepted
EndTime:06/02/17 22:10
*/
#include <stdio.h>

int main()
{
	int max,temp;
	while(scanf("%d",&temp)!=EOF)
	{
		max=temp;
		int n=9;
		while(n--)
		{
			scanf("%d",&temp);
			if(temp>max)
				max=temp;
		}
		printf("max=%d\n",max);
	}
}
/*
InputData:
10 22 23 152 65 79 85 96 32 1
OutputData:
max=152
*/

