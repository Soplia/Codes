#include <stdio.h>

int main()
{
	printf("%d\n", sizeof(void *));
	printf("%d\n", sizeof(int *));
	int *p;
	int i = 10;
	p = &i;
	*p = NULL;
	printf("%d\n", i );
	return 0;
}
