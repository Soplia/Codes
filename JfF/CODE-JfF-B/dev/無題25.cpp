#include <stdio.h>
#define N 1000

char *myDelete(char *a,char b,char *d)
{
	char *c=d;

	while (*a!=0)
	{
		if(*a!=b)
		{
			*d=*a;
			d++;
		}
			
		a++;
	}
	*d=0;
	return c;
}

int main()
{
	char a[N];

	for(int i=0;i<10;i++)
	{
		char d[N],b,c[N]="ewqrrrrrrrrrrrrrrrrrrrrrrrrewqrrrrrrrrrrrrrrrrrrrrrrrrewewqrrrrrrrrrrrrrrrrrrrrrrrrewqrrrrrrrrrrrrrrrrrrrrrrrr";
		b='e';
		char *t=NULL;
		t=myDelete(a,b,d);
		if(t==NULL)
			printf("t=NULL\n");
		else
			printf("%s\n",t);
	}
	return 0;
}

/*
Subject:
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:
Result:
EndTime:
*/

/*
InputData:
ewqrrrrrrrrrrrrrrrrrrrrrrrrewqrrrrrrrrrrrrrrrrrrrrrrrrewewqrrrrrrrrrrrrrrrrrrrrrrrrewqrrrrrrrrrrrrrrrrrrrrrrrr



rqqqqqqqqqqqqqqqqqqqqqqqqq
OutputData:

*/

