#include <stdio.h>
#define N 100

int myStrlen(char *a)
{
	int len=0;
	//öa??w??ÊC?s??C??I¥ê¢{CI
	//LÁìpæ??¥Ý?¢B 
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
