/*
Subject:µ¥´ÊÌæ»» 
ID:1111
Complier:Devcpp
Author:JiaruiXie
StartTime:28/03/17 09:36
Result:
EndTime:
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 200

char str[N];
char des[N];
char ch[N];
char aim[N];
char cha[N];

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		scanf("%s%s",&aim,&cha);
		int pos=0,che=0;
		while(!isspace(str[pos]))
		{
			ch[pos]=str[pos]++;
		}
		ch[pos]=0;
		if(strcmp(ch,aim)==0)
		{
			while(*des++=*aim++)
		}
	}
	return 0;
}

/*
InputData:
You want someone to help you
You
I
OutputData:
I want someone to help you
*/

