/*
Subject:»¹ÊÇA+B 
ID:1015
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 08:52
Result:Accepted
EndTime:20/03/17 08:57
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int a,b,k;
	while(scanf("%d%d%d",&a,&b,&k)!=EOF)
	{
		if(a==0&&b==0)
			break;
		
		int temp=a+b;
		int aa,bb;
		int flag=1;
		while(k--)
		{
			aa=a%10;
			a/=10;
			bb=b%10;
			b/=10;
			if(aa!=bb)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			puts("-1");
		else
			printf("%d\n",temp);
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

