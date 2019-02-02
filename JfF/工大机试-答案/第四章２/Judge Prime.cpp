/*
Subject:Judge Prime
ID:4.6
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 18:02
Result:Accepted
EndTime:04/02/17 18:15
*/
#include <stdio.h>
#include <math.h>

int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		if(a<=0||a==1)
			printf("no\n");
		else
		{
			int flag=1;
			int bound=sqrt(a)+1;
			for(int i=2;i<bound;i++)
				if(a%i==0)
				{
					flag=0;
					break;
				}
				
			printf("%s\n",flag?"yes":"no");
		}
	}
	return 0;
}
/*
InputData:
13
OutputData:
yes
*/

