/*
Subject:‹ài‚©‚Ë‚à‚¿j 
ID:2012_1 
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 16:31
Result:Accepted
EndTime:06/02/17 16:46
*/
#include <stdio.h>

int main()
{
	int a=10,b=1,ans1=0,ans2=0;
	for(int i=1;i<=30;i++)
	{
		ans1+=a;
		ans2+=b;
		b*=2;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
/*
InputData:

OutputData:

*/

