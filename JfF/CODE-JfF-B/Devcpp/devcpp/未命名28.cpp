//用选择排序法对6个数进行排序(从小到大)
#include <stdio.h>
int main()
{
	int min=0;
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=10-i;
	for(int i=0;i<9;i++)
	{
		for(int j=i;j<10;j++)
			if(a[j]<=a[min])
				min=j;
		int temp;
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	for(int i=0;i<10;i++)
		printf("%d\n",a[i]);	
	return 0;
}
