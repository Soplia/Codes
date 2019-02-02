/*
	Subject:高精度_整数_加法 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:2-9-1
	Date_Begin:14/01/17 21:17
	Date_End:15/01/17 09:20
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int len=1000;

typedef struct bigInteger
{
	int digit[len];
	int size;
	//进行初始化 
	void init()
	{
		size=0;
		for(int i=0;i<len;i++)
			digit[i]=0;
	}
	
	//从字符串中提取大整数
	void set(char *a)
	{
		//首先进行初始化 
		init();
		int n=strlen(a);
		for(char *p=a+n-1,j=1,c=1,t=0;p>=a;p--) 
		{
			t+=(*p-'0')*c;
			c*=10;
			j++;
			if(j==4||p==a)
			{
				digit[size++]=t;
				j=1;
				c=1;
				t=0;
			}
		}
	} 
	
	//输出
	void output()
	{
		for(int i=size-1;i>=0;i--)
			if(i==size-1)
				printf("%d",digit[i]);	
			else
				printf("%04d",digit[i]);
		printf("\n");
	} 
	
	bigInteger operator + (const bigInteger &a) const
	{
		bigInteger c;
		c.init();
		int temp=0;
		int carry=0;
		for(int i=0;i<size||i<a.size;i++)
		{
			temp=digit[i]+a.digit[i]+carry;
			carry=temp/10000;
			temp%=10000;
			c.digit[c.size++]=temp;
		}
		//这个地方加完之后有可能不是1呢 
		if(carry!=0)
			c.digit[c.size++]=carry;
		return c;	
	}
}BI;

int main()
{
//	char *a=(char *)malloc(sizeof(char)*len);
//	if(a==NULL)
//	{
//		printf("内存分配失败！\n");
//		goto Solve;
//	}
//	else if(a!=NULL)
//		printf("内存a分配成功\n");
//		
//	char *b=(char *)malloc(sizeof(char)*len);
//	if(b==NULL)
//	{
//		printf("内存分配失败！\n");
//		goto Solve;
//	}
//	else if(b!=NULL)
//		printf("内存b分配成功\n");
		
	char a[len],b[len];
		
	while(scanf("%s%s",a,b)!=EOF)
	{
		 BI aa,bb,c;
		 aa.set(a);
		 bb.set(b);
		 c=aa+bb;
		 c.output();
	}
	
//	goto Solve;
	 
//	Solve://只要内存未成功分配，把所有使用malloc分配的内存空间都释放掉。 
//		if(a!=NULL)
//		{
//			free(a);
//			printf("已经释放a\n");
//		}
//		if(b!=NULL)
//		{
//			free(b);
//			printf("已经释放b\n");
//		}
			
			
	return 0;
}
/*
测试数据
样例输入
2 6
10000000000000000000  10000000000000000000000000000000
样例输出
8
10000000000010000000000000000000
*/

















