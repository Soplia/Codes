#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[5][5];
	int(*p)[5];
	p = a;
	printf("a = %#p, p = %#p", &a[4][2], &p[4][2]);
	char * ch = "Hello World";
	printf("%d\n", strlen(ch));
	system("pause");
	return 0;
}