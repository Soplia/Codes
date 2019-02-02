/*
	Subject:高精度_整数_高精度*低精度 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-9-2
	Date_Begin:15/01/17 10:18
	Date_End:
*/
#include <stdio.h>

const int len=1000;

typedef struct bigInteger
{
	int digit[len];
	int size;
	
	void init()
	{
		size=0;
		for(int i=0;i<len;i++)
			digit[i]=0;
	}
	
	//这次的输入是一个小整数，所以不需要使用字符串输入 
	void set(int x)
	{
		init();
		do
		{
			int temp=x%10000;
			x/=10000;
			digit[size++]=temp;
		}while(x!=0);
	}
	
	bigInteger operator * (int x) const
	{
		int temp=0;
		int carry=0;
		bigInteger c;
		c.init();
		for(int i=0;i<size;i++)
		{
			temp=digit[i]*x+carry;
			carry=temp/10000;
			temp%=10000;
			c.digit[c.size++]=temp;
		}
		if(carry!=0)
			c.digit[c.size++]=carry;
		return c;
	}
	//不知道为什么使用*=不行 
	bigInteger operator *= (int x) const
	{
		bigInteger c;
		c.init();
		c=c*x;
		return c;
	}
	
	void output()
	{
		for(int *p=digit+size-1;p>=digit;p--)
			if(p==digit+size-1)
				printf("%d",*p);
			else
				printf("%04d",*p);
		printf("\n");
	}
}BI;

int main()
{
	int x;
	//如果要使用二分求幂，需要重写两个大整数相乘 
	while(scanf("%d",&x)!=EOF)
	{
		BI ans;
		ans.set(1);
		for(int i=1;i<=x;i++)
			ans=ans*i;
		ans.output();
	}
}

/*
测试数据
样例输入
4
5
15
样例输出
24
120
1307674368000
*/


























