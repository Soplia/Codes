#include <stdio.h>

int main()
{
	char a;
	scanf("%c",&a);
	int size='a'-'A';
	printf("%c_%d\n",a-size,a-size);
	return 0;
} 
