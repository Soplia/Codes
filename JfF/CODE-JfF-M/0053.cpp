#include <stdio.h>

union
{
	int i;
	char a[2];
}*p, u;

int main()
{
	p = &u;
	p->a[0] = 'H';
	p->a[1] = 'A';
	printf("%d\n", 'H');
	printf("%d\n", 'A');
	printf("%d\n", p->i);
	return 0;
}
