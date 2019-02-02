#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
	int a;
	int arr[];
}type_a;

int main()
{
	printf("%d\n", sizeof(type_a));
	type_a *p = (type_a*)malloc(sizeof(type_a) + sizeof(int) * 100);
	printf("%d\n", sizeof(*p));
	printf("%d\n", p);
	free(p);
	printf("%d\n", p);
	p = NULL;
	printf("%d\n", p);
	return 0;
}
