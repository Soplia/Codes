//������a��ȫ��Ԫ�ؼ�1, �����a
#include <stdio.h>

//�ܶ���֮���Զ���֮��ʹ��ָ������ָ���ʱ����Ҫ���к����ķ���ֵ���͡� 
void add(int *,int );

int main()
{
	void (*p)(int *,int);
	p=add;
	
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=i+1;
	(*p)(a,10);
	
	for(int i=0;i<10;i++)
		printf("%-3d",a[i]);
	return 0;
}

void add(int *a,int b)
{
	for(int *p=a;p<a+b;p++)
		(*p)++;
}
