/*
Subject:
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:
Result:
EndTime:
*/
#include <stdio.h>
#include <ctype.h> 
#define N 100

char name[N],n[N];

int main()
{
	while(gets(name))
	{
		int i=0;
		char *temp=name;
		while(!isalpha(*temp))
			temp++;
		*temp=toupper(*temp);
		
		while(!isspace(*temp))
		{
			n[i++]=*temp;
			temp++;
		}
		
		n[i++]=' ';
		
		while(!isalpha(*temp))
			temp++;
		*temp=toupper(*temp);
		
		while(!isspace(*temp))
		{
			n[i++]=*temp;
			temp++;
		}
		
		n[i]=0;
		puts(n);
	}
	return 0;
}
/*
InputData:

OutputData:

*/

