#include <stdio.h>
int main()
{
	int line=9;
	for(int i=1;i<=line;i++)
	{
		for(int j=1;j<=i;j++)
		//�ܹ�ʹ�������գ�����Ҫ������� 
			printf("%d��%d=%-3d",j,i,i*j);  
		printf("\n");
	}
	return 0;
}
