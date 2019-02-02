#include <stdio.h>

char * GetStr(void)
{
	char *p = "HelloWorld";
	printf("%d\n", p);
	return p;
}

int main()
{
	char *p = NULL;
	p = GetStr();
	printf("%d\n", p);
	puts(p);
	return 0;
}
