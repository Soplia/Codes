//������a��ȫ��Ԫ�ؼ�1, �����a
#include<stdio.h>

int main()
{
	int a[10];
	int *p=a;
	for(int i=0;i<10;i++)
	{
		*(a+i)=i+1;
		printf("%-3d",*(a+i));
	}
		
	return 0;
}
