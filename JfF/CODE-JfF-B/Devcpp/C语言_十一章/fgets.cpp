#include<stdio.h>
int main()
{
	int n=10;
	char a[n];
	fgets(a,n*sizeof(char),stdin);
	//gets(a);
	puts(a);
	return 0;
}
/*
测试数据
样例输入
i miss you do you miss me
样例输出

*/
 
