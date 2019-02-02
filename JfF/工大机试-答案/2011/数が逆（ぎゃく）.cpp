/*
Subject:”‚ª‹ti‚¬‚á‚­j 
ID:2011_1
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 19:54
Result:Accepted
EndTime:
*/
#include <stdio.h>
#include <string.h>
#define N 300

int main()
{
	char a[N];
	while(~scanf("%s",a))
	{
		for(int i=strlen(a)-1;i>=0;i--)
			printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
/*
InputData:
hdssg
OutputData:
gssdh
*/

