/*
Subject:deleteChar
ID:2009_4
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 22:44
Result:Accepted
EndTime:06/02/17 22:50
*/
#include <stdio.h>
#define N 1000

int main()
{
	char s[N],a[N],c;
	while(gets(s))
	{
		scanf("%c",&c);
		getchar();
		int j=0;
		for(int i=0;s[i]!=0;i++)
			if(s[i]!=c)
				a[j++]=s[i];
		a[j]=0;
		puts(a);
	}
	return 0;
}
/*
InputData:
heallo
a
OutputData:
hello
*/

