//1、请在屏幕上输出20行星号，每行星号由8个*组成。
//2、请输出1—200之间的所有偶数。
#include<stdio.h>
int main()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<8;j++)
	printf("*");
	printf("\n");
	}
	int count=0;
	for(int i=1;i<=200;i++)
	{
		if(i%2==0)
		{
			count++;
			printf("%5d",i);
		}
		if(count%10==0)
		printf("\n");
	}
	return 0;
	
}

