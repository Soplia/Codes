/*
	Subject:计算a+aa+aaa+...+a.....a 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.2.3
	Date_Begin:29/01/17 20:13
	Date_End:29/01/17 20:18
*/
#include <stdio.h>

int main()
{
	int a,size;
	while(scanf("%d%d",&a,&size)!=EOF)	
	{
		int sum=0;
		int term=0;
		for(int i=1;i<=size;i++)
		{
			term=term*10+a;
			sum+=term;
			printf("第%d次:term=%d,sum=%d\n",i,term,sum);
		}
		printf("%d\n",sum);
	}
	return 0;
} 
/*
输入数据
2 8
*/


























