//用冒泡排序法对6个数进行排序(从小到大)
#include<stdio.h>
#include <math.h>

int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	{
		a[i]=i;
		printf("%-3d",a[i]);
	}
	for(int i=0;i<9;i++)
		for(int j=0;j<9-i;j++)
			if(a[j]>a[j+1])
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	for(int i=0;i<10;i++)
		printf("%d\n",a[i]);
	return 0;
	
}
