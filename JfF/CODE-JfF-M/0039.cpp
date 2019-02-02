#include <stdio.h>
#include <stdlib.h>

void DeleteChar(char **p)
{
	free(*p);
	*p = NULL;
}

int main()
{
	char *p = (char *)malloc(sizeof(char) * 10);
	printf("%d\n", p);
	DeleteChar(&p);
	printf("%d\n", p);
	return 0;
}
