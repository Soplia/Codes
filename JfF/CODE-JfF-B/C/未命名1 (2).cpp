#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocateMemory(char **p,int);

int main()
{
	char *a=NULL;
	allocateMemory(&a,10);
	strcpy(a,"fdasf");
	puts(a);
	free(a);
	return 0;
}

void allocateMemory(char **p,int num)
{
	*p=(char *)malloc(sizeof(char)*num);
}
