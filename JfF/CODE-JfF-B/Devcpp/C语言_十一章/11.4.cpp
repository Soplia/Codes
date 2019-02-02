#include <stdio.h>

//����3���Nû�н�� 
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

//����1 ��ά���鴫���β�ʱʹ��a[][4]��*a��ʲô���� 
//�Լ�Ϊʲô 
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
	//����2���ߴ����β���ʲô��ͬ 
	//����ά�������ָ�� 
	output(*a,n);
	//ֱ�Ӵ���ά�����ָ�� 
	transpose1(a,n);
	//����ά�������ָ�� 
	output(*a,n);
	transpose2(a,n);
	output(*a,n);
	transpose3(*a,n);
	output(*a,n);
	return 0;
}


























