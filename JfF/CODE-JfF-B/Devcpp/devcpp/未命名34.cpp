#include<stdio.h>

int get1(int);
int get2(int,int);

int main()
{
	printf("%-3d",get2(2,3));
	return 0;
}

int get1(int a)
{
	int sum=1;
	for(int i=1;i<=a;i++)
		sum*=i;
	return sum;
}

int get2(int m,int n)
{
	int a=get1(n);
	int b=get1(m);
	int c=get1(n-m);
	return a/(b*c);
}
