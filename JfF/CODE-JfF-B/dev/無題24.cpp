#include <stdio.h>
#include <ctype.h>
#define N 100

int main()
{
	char a[N];
	while(gets(a))
	{
		int flag=1;
		int count=0;
		for(int i=0;a[i]!=0;i++)
			if(!isalpha(a[i]))
				flag=1;
			else if(isalpha(a[i])&&flag)
			{
				count++;
				flag=0;
			}
		printf("%d\n",count);
	}
	return 0;
		
}
