#include <stdio.h>

char* Func(void)
{
	char str[100] = "Hello World\n";
	puts(str);
	printf("%d\n", str);
	return str;
}

int main()
{
	char *p = Func();
	puts(p);
	printf("%d\n", p);
	return 0;
}
