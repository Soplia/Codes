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
#define N 100

char a[N],b[N];

int main()
{
	gets(b);
	gets(a);
	
	char *a1=a,*b1=b;
	char *c=b;
	
	while(*b1!=0)
		b1++;
		
	while(*a1!=0)
	{
		*b1=*a1;
		b1++;
		a1++;
	}
	
	*b1=0;
	
	puts(c);
	
	return 0;
}
/*
InputData:

OutputData:

*/

