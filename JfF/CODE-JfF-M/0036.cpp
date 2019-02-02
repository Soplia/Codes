#include <stdio.h>

void DisSize(char a[100])
{
	printf("%d\n", sizeof(a));
}

int main()
{
	char array[] = "Hello World";
	char *p = array;
	printf("%d-%d\n", sizeof(array), sizeof(p));
	DisSize(array);
	return 0;
}
