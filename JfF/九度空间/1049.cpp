/*
Subject:字符串中去特定字符 
ID:1049
Complier:Devcpp
Author:JiaruiXie
StartTime:28/03/17 09:48
Result:Accepted
EndTime:28/03/17 09:53
*/

#include <stdio.h>
#define N 200

char str[N];
char aim;

int main()
{
	while(gets(str))
	{
		scanf("%c",&aim);
		getchar();
		int j,i;
		for(i=0,j=0;str[i]!=0;i++)
			if(str[i]!=aim)
				str[j++]=str[i];
		str[j]=0;
		puts(str);
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

