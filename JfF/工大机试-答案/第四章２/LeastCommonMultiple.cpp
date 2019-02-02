/*
Subject:Least Commont Multiple
ID:4.5
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 17:58
Result:
EndTime:
*/
#include <stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int tempa=a,tempb=b;
		while(a!=b)
		{
			if(a>b)
				a-=b;
			else
				b-=a;
		}
		printf("%d\n",tempa*tempb/a);
	}
	return 0;
}
/*
InputData:
10 14
OutputData:
70
*/


