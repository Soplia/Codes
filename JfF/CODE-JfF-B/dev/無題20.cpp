#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	char b[100]="213",*t=b;
	a=123;
	itoa(a,b,10);
	puts(b);
//	a=atoi(b);
//	printf("%d\n",a);
	return 0;
}
