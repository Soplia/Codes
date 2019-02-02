//输入30个字符,统计其中数字字符的个数 
#include <stdio.h>
int main()
{
	int count=0;
	char a;
	int b;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&b);
	//	printf("The input number is:%d\n",b);
		if(b>=0&&b<=9)
			count++;
	}
	printf("The number is:%d\n",count);
	return 0;
}
