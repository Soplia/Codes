//������������нϴ����
#include<stdio.h>

int getMax(int,int);

int main()
{
	printf("%d",getMax(2,3));
	return 0;
}

int getMax(int a,int b)
{
	return a>b?a:b;
}
