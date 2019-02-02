#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	for (double y = 1; y >= -1; y -= 0.1)
	{
		int m = acos(y) * 10;
		int i;
		for (i = 1; i < m; i++)
			printf(" ");
		printf("*");
		for (; i < 62 - m; i++)
			printf(" ");
		printf("*\n");
	}

	system("pause");
	return 0;
}