/*
Subject:Greast Common Divisor
ID:4.4
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 17:54
Result:Accept 
EndTime:04/02/17 17:57
*/
#include <stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		while(a!=b)
		{
			if(a>b)
				a-=b;
			else
				b-=a;
		}
		printf("%d\n",a);
	}
	return 0;
}
/*
InputData:
49 14
OutputData:
7
*/


