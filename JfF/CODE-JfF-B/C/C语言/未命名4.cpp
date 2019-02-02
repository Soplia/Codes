#include <stdio.h>

#define STR(A) _STR(A)
#define _STR(A) #A
#define T  (2)
int main()
{
	printf("%s\n",STR(T));
	return 0;
}
