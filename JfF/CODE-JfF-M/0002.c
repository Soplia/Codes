#include <stdio.h>

int main()
{
	const int type = 1;
	int array[type];
	scanf("%d", &type);
	switch (type)
	{
		case 1: printf("1\n");break;
		case 2: printf("2\n");break;
		default:break;
	}
	return 0;
}
