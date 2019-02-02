#include<stdio.h>

void swap1(int *,int *);
void swap2(int *,int *);
void swap3(int *,int *);

int main()
{
	int a, b;
	scanf("%d%d",&a,&b);
	swap1(&a,&b);
	printf("%d,%d",a,b);
	return 0;
}

void swap1(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

//这个地方只是交换了变量的地址，而此时的地址也只是一个临时变量而已。 
void swap2(int *a,int *b)
{
	int *temp;
	temp=a;
	a=b;
	b=temp;
}

void swap3(int *a,int *b)
{
	int *temp;
	*temp=*a;
	*a=*b;
	*b=*temp;
}
