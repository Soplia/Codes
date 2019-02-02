#include <stdio.h>
#define N 100

int myStrlen(char *a)
{
	int len=0;
	//因a??指??量，?行??，??来的是一个副本，它的
	//有效作用域??是在?个函数中。 
	for(;*a!=0;a++)
		len++;
	return len;
}

int main()
{
	char a[N];
	while(gets(a))
	{
		printf("%d\n",myStrlen(a));
		puts(a);
	}
	return 0;
}
