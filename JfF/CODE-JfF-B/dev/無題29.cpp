#include <stdio.h>
#define N 100

int main()
{
	char a[N];
	while(gets(a))
	{
		char c;
		int i,j;
		scanf("%c",&c);
		for(i=j=0;a[i]!=0;i++) 
			if(a[i]!=c)
			{
				a[j]=a[i];
				j++;
			}
		a[j]=0;
		puts(a);
	}
	return 0;
}
