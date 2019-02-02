//用数组求fibonacci数列的前20个数
#include<stdio.h>
int main()
{
	int a[20]={1,1};
	for(int i=2;i<20;i++)
		a[i]=a[i-1]+a[i-2];
	for(int i=0;i<20;i++)
	{
		if(i%5==0)
			printf("\n");
		printf("%-3d",a[i]);
		
	}
		
	return 0;
}
