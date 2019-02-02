//求数组中最大和最小元素
#include <stdio.h>

int *getMax(int *,int );
int *getMin(int *,int );
void getMax_Min(int *,int );

int main()
{
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=i+1;
	//printf("Max=%-3d,Min=%-3d",*getMax(a,10),*getMin(a,10));
	getMax_Min(a,10);
	//在这里需要讨论一下静态变量 
	int ma=Max,mi=Min;
	printf("Max=%-3d,Min=%-3d",ma,mi);
	return 0;
}

int *getMax(int *a,int size)
{
	int max=-9999;
	int pos=-1;
	for(int i=0;i<size;i++)
		if(a[i]>max)
		{
			max=a[i];
			pos=i;
		}
	return a+pos;
} 

int *getMin(int *a,int size)
{
	int min=10000;
	int pos=-1;
	for(int i=0;i<size;i++)
		if(a[i]<min)
		{
			min=a[i];
			pos=i;
		}
	return a+pos;
}

void getMax_Min(int *a,int size)
{
	static Max=-9999,min=9999;
	for(int i=0;i<size;i++)
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
}
