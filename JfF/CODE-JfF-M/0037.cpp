#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void GetMem(char **p, int num)
{
	*p = (char *)malloc(sizeof(char) * num);
}

int main()
{
	char *p = NULL;
	GetMem(&p, 100);
	strcpy(p, "HelloWorld");
	puts(p);
	return 0;
}
*/

void GetMem(char *p, int num)
{
	p = (char *)malloc(sizeof(char) * num);                                           
}

int main()
{
	char *p = NULL;
	GetMem(p, 100);
	strcpy(p, "HelloWorld");
	puts(p);
	return 0;
}

