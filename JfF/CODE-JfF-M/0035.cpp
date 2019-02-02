#include <stdio.h>

char * GetStr(void)
{
	char *p = "Hello World";
	return p;
}

int main()
{
	char *p = NULL;
	p = GetStr();
	puts(p);
	return 0;
}
