#include <stdio.h>

void InputArray(int *pa,int n);
void OutputArray(int *pa,int n);

int main()
{
	int a[5];
	printf("Input five numbers:\n");
	InputArray(a,5);
	OutputArray(a,5);
	return 0;
}

void InputArray(int *pa,int n)
{
	//此处是程序陷入无限循环中 
	//for(;pa<pa+n;pa++)
	for(int *t=pa;t<pa+n;t++)
		scanf("%d",t);
}

void OutputArray(int *pa,int n)
{
	//for(;pa<pa+n;pa++)
	for(int *t=pa;t<pa+n;t++)
		printf("%4d",*t);
	printf("\n");
}
