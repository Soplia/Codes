//ʹ����Ԫ��a[0]��a[9]��ֵΪ0��9, �������ú������
#include<stdio.h>
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=i;
	for(int i=0,j=9;i<j;i++,j--)
	{
		int b;
		b=a[i];
		a[i]=a[j];
		a[j]=b;
	}
	for(int i=0;i<10;i++)
		printf("%-3d",a[i]);
	return 0;
}
