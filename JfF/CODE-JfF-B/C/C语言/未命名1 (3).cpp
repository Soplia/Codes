#include "stdio.h"
#include <1.h>
#define NL "\n"
#define D "%d"
#define D1 D NL
#define PR printf

int main()
{
	printf("Hello World" NL );
	printf(D1,123);
	PR("Hello World" NL);
	return 0;
}
