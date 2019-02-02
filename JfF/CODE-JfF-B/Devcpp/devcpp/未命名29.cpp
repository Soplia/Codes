//冒泡的改进方法
#include<stdio.h>
int main()
{
	int a[10];
	int count=0;
	for(int i=0;i<10;i++)
		a[i]=i+1;
	bool flag;
	do
	{
		flag=false;
		int j=1;
		for(int i=0;i<10-j;i++)
			if(a[i]>a[i+1])
			{
				int temp;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				flag=true;
			}
		
		count++;
		j++;
	}while(flag);
	printf("总共进行了%d次排序！\n",count);
	return 0;
}
