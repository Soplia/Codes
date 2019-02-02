/*
Subject:wanshu
ID:2010_1
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 20:31
Result:Accepted
EndTime:06/02/17 20:43
*/
#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int flag=1,ans;
		for(int i=1;i<=n;i++)
		{
			ans=0;
			for(int j=1;j<i;j++)
				if(i%j==0)
					ans+=j;
			
			if(ans==i)
				if(flag)
				{
					printf("%d",i);
					flag=0;
				}
				else
					printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}
/*
InputData:
6
OutputData:
6
*/

