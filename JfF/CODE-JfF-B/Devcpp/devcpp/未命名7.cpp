//1��������Ļ�����20���Ǻţ�ÿ���Ǻ���8��*��ɡ�
//2�������1��200֮�������ż����
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

