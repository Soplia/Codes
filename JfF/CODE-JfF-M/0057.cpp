#include <stdio.h>

int main()
{
	int i = 0;
	int j = (i++, i++, i++);
	printf("i = %d, j = %d\n",i, j);
	i = 0;
	//int m = (++i) + (++i) + (++i);
	int k = (i++) + (i++) + (i++);
	printf("i = %d, k = %d\n",i, k);
	i = 3;
	int n = (++i, i++, i + 10);
	printf("i = %d, n = %d\n",i, n);
	
	i = 3;
	//int h = ++i+++i+++i;
	//printf("i = %d, h = %d\n",i, h);
	
	
	printf("%d, %d\n",(-3) / 2, (-3) % 2);
	printf("%d, %d\n",3 / (-2), 3 % (-2));
	return 0;
}
