//Êä³öÁâĞÎ
#include <stdio.h>
int main()
{
	int total=19;
	int up=total/2+1;
	int down=total/2;
	for(int i=1;i<=up;i++)
	{
		for(int j=1;j<=up-i;j++)
			printf(" ");
		for(int k=1;k<=i;k++)
			printf(" *");
		printf("\n");
	}
	for(int i=1;i<=down;i++)
	{
		for(int j=1;j<=i;j++)
			printf(" ");
		for(int k=1;k<=down-i+1;k++)
			printf(" *");
		printf("\n");
	}
	return 0;
}
