//ʵ��һά���������ݵ�˳������
#include<stdio.h>

void sort(int *,int);

int main()
{
	int size=10 ;
	int a[size];
	for(int i=0;i<size;i++)
		a[i]=10-i;
	void (*p)(int *,int);
	p=sort;
	(*p)(a,size);
	for(int i=0;i<size;i++)
		printf("%-3d",a[i]);
	return 0;
}

void sort(int *a,int size)
{
	bool flag;
	int j=1;
	do 
	{
		flag=false;
		for(int i=0;i<size-j;i++)
			if(a[i]>a[i+1])
			{
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				flag=true;
			}
		j++;//ע��J�ŵ�λ�á� 
	}while(flag);
}
