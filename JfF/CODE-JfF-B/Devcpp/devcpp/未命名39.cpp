//��extern�����ⲿ��������չȫ�ֱ�����������
#include <stdio.h>

int max(int ,int );

int main()
{
	extern int a,b;
	printf("%d\n",max(a,b));
}

int a=1,b=2;

int max(int a,int b)
{
	return a>b?a:b;
}
