#include <stdio.h>

//问题3这个N没有解决 
#define N 4

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
} 

void output(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",a[i*n+j]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

//问题1 二维数组传递形参时使用a[][4]和*a有什么区别 
//以及为什么 
void transpose1(int a[][N],int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			swap(&a[i][j],&a[j][i]);
}

void transpose2(int (*a)[N],int n) 
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			swap(&a[i][j],&a[j][i]);
} 

void transpose3(int *a,int n)
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			swap(&a[i*n+j],&a[j*n+i]);
}
 
int main()
{
	int a[][4]={1,1,1,1,
			    2,2,2,2,
				3,3,3,3,
				4,4,4,4};
	int n=4;
	//问题2两者传送形参有什么不同 
	//传二维数组的列指针 
	output(*a,n);
	//直接传二维数组的指针 
	transpose1(a,n);
	//传二维数组的列指针 
	output(*a,n);
	transpose2(a,n);
	output(*a,n);
	transpose3(*a,n);
	output(*a,n);
	return 0;
}


























