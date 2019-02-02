#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 2;
	int b = 3;
	const int  * const p = &a
	//const int  * const p = (int *)malloc(sizeof(int));
	*p = 3;
	p = &b;

	return 0;
}
