#include <stdio.h>
#include <assert.h>
#define N 100

char *myCpy(char *a,char *b)
{
	assert(a!=NULL&&b!=NULL);
	char *c=a;
	while(*a++=*b++);
	return c;
}

int main()
{
	char a[N],b[N];
	while(gets(a))
	{
		int i,j;
		for(i=0,j=0;a[i]!=0;i++)
		{
			b[j++]=a[i];
			b[j++]=' ';
		}
		b[j]=0;
		puts(b);
	}
}
