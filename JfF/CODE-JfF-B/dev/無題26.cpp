#include <stdio.h>
#include <ctype.h>
#define N 100

int main()
{ 
	char a[N],b[N];
	int k;
	while(gets(a))
	{
		int flag=1;
		k=0;
		for(int i=0;a[i]!=0;i++)
			if(!isalpha(a[i]))
			{
				flag=1;
				b[k++]=a[i];
			}	
			else if(isalpha(a[i])&&flag)
			{
				b[k++]=' ';
				b[k++]=a[i];
				flag=0;
			}
		b[k]=0;
		puts(b);
	}
	return 0;
}
