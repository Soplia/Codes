//输出等腰三角形
#include <stdio.h>
int main()
{
	int line=15;
	for(int i=1;i<line;i++)
	{
		for(int j=1;j<=line-i-1;j++)
			printf(" ");
		for(int k=1;k<=i;k++)
			printf(" *");
		printf("\n");
	}
	return 0;
}
