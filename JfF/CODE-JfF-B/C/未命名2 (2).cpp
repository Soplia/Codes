#include <stdio.h>
#include <string.h>

char *fun1(char *p)
{
	puts(p);
	return p;
}

char *fun2(char *p)
{
	puts(p);
	return p;
}

char *fun3(char *p)
{
	puts(p);
	return p;
}

int main()
{
	char * (*p[3])(char *p);
	p[0]=fun1;
	p[1]=&fun2;
	p[2]=fun3;
	p[0]("fun1");
	p[1]("fun2");
	p[2]("fun3");
	return 0;
}
