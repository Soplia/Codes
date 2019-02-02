/*
Subject:‚Ü‚¾A+B 
ID:1015
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 12:07
EndTime:
*/
#include <stdio.h>

int main()
{
	int a,b,c;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0||b==0)
			break;
		scanf("%d",&c);
		int tA=a,tB=b;
		int flag=1;
		while(c--)
		{
			int i=a%10;
			int j=b%10;
			if(i!=j)
			{
				flag=0;
				printf("%d\n",tA+tB);
				break;
			}
			a/=10;
			b/=10;
		}
		if(flag)
			printf("-1\n");
	}
	return 0;
}
/*
InputData:
1 2 1
11 21 1
108 8 2
36 64 3
0 0 1
OutputData:
3
-1
-1
100
*/

