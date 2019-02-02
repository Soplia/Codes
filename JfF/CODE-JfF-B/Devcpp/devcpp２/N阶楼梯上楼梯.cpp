/*
	Subject:N阶楼梯上楼梯 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:7-1-1 
	Date_Begin:21/01/17 09:28
	Date_End:21/01/17 09:37
*/
#include <stdio.h>


int main()
{
	int x[100],a;
	x[1]=1;
	x[2]=2;
	for(int i=3;i<100;i++)
		x[i]=x[i-1]+x[i-2];
	while(scanf("%d",&a)!=EOF)
		printf("%d\n",x[a]);
	return 0;
}

/*
测试数据
样例输入
4
样例输出
5
*/

