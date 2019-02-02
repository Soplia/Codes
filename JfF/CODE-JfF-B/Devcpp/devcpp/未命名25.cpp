//用筛选法求1—100间的素数
#include <stdio.h>
#include <math.h>

bool is(int a);
void f1(int a);
void f2(int a[]);

int main()
{
	int a[100];
	for(int i=0;i<100;i++)
		a[i]=i+1;
	f1(100);
	printf("\n");
	f2(a);
	return 0;
}

bool is(int a)
{
	if(a==1)
		return false;
	for(int i=2;i<=sqrt(a);i++)
		if(a%i==0)
			return false;
	return true;
}

void f1(int a)
{
	int count=0;
	for(int i=1;i<=a;i++)
		if(is(i))
		{
			printf("%-4d",i);
			count++;
			if(count%5==0)
				printf("\n");
		}
}

void f2(int a[])
{
	int count=0;
	a[0]=0;
	for(int i=0;i<100;i++)
		for(int j=2;j<=100;j++)
			if(a[i]%j==0&&a[i]!=j)
				a[i]=0;
	for(int i=0;i<100;i++)
		if(a[i]!=0)
		{
			printf("%-4d",a[i]);
			count++;
			if(count%5==0)
				printf("\n");
		}
}
