//判断一个数m是否为素数
#include<stdio.h>
bool is(int );
int main()
{
	int count=0;
	for(int i=1;i<=200;i++)
	{
		if(is(i))
		{
			printf("%-4d",i);
			count++;
			if(count%5==0)
				printf("\n");
		}
	}
	return 0;
}
bool is(int a)
{
	for(int i=2;i<=a-1;i++)
		if(a%i==0)
			return false;
	return true;
}
