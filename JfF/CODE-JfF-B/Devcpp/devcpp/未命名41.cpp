//求一维数组中全部元素的和
#include<stdio.h>

int add(int *a);

int main()
{
	int (*p)(int *);
	p=add;
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=i+1;
	printf("%d",(*p)(a));
	return 0;
}

int add(int *a)
{
	int sum=0;
	for(int i=0;i<10;i++)
		sum+=a[i];
	return sum;
}
