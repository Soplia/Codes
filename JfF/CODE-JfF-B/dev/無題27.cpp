#include <stdio.h>
#define N 100

int myLen(char *a)
{
	int len=0;
	while(*a++!=0)
		len++;
	return len;
}

int main()
{
	char a[N];
	while(gets(a))
	{
		int len=myLen(a);
		
		for(int i=0,j=len-1;i<j;i++,j--)
		{
			
			char temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		puts(a);
	}
	return 0;
}
