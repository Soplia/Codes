//求正整数n的阶乘 n! , n由键盘输入
#include<stdio.h>
int main()
{
	int n;
	printf("Input the n:\n");
	scanf("%d",&n);
	//验证是否合法 
	int sum=1;
	for(int i=1;i<=n;i++)
		sum*=i;
	printf("The result is:%d\n",sum);
	return 0;
}
