//输入一个数据，在已知数组中查找是否有该数据
#include <stdio.h>
int main()
{
	int a;
	int b[100];
	for(int i=0;i<100;i++)
		b[i]=i;
	scanf("%d",&a);
	for(int i=0;i<100;i++)
		if(b[i]==a)
			printf("i=%d\n",i);
	for(int low=0,high=99;low<=high;)
	{
		int mid=(low+high)/2;
		if(b[mid]==a)
		{
			printf("mid=%d\n",mid);
			break;
		}
		else
		{
			if(a<b[mid])
				high=mid-1;
			else
				low=mid+1;
		}
	}
	return 0;
}
