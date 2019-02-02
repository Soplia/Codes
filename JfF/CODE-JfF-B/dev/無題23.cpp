#include<stdio.h>
#define N 100

char *myCpy(char *a,char *b) 
{
	char *c=a;
	while((*a++=*b++)!=0);
	return c;
}

int myLen(char *a)
{
	int len=0;
	for(;*a!=0;a++)
		len++;
	return len;
}

char *myCat(char *a,char *b)
{
	char *c=a;
	while(*a!=0)
		a++;
	while((*a++=*b++)!=0);
	return c;
}

int myCmp(char *a,char *b)
{
	for(;*a==*b;a++,b++)
		if(*a==0)
			return 0;
	return *a>*b?1:-1;
}

int main()
{
	char a[N],b[N];
	while(gets(a))
	{
		printf("a.len=%d\n",myLen(a));
		myCpy(b,a);
		printf("b=%s\n",b);
		myCat(b,a);
		printf("a=%s\n",a);
		printf("%d\n",myCmp(a,b));
	}
	return 0;
}


















