/*
Subject:Connect
ID:2012_3
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 17:40
Result:Accepted
EndTime:06/02/17 17:47
*/
#include <stdio.h>
#include <string.h>
#define N 100

void MyStrcat(char dstStr[],char srcStr[])
{
	char *t=dstStr;
	while(*dstStr!=0)
		dstStr++;
	for(;*srcStr!=0;srcStr++,dstStr++)
		*dstStr=*srcStr;
	*dstStr=0;
	dstStr=t;
}

int main()
{
	char s[N],d[N];
	while(scanf("%s%s",d,s)!=EOF)
	{
		MyStrcat(d,s);
		puts(d);
	}
	return 0;
}
/*
InputData:
hello world
good morning
OutputData:
helloworld
goodmorning
*/

