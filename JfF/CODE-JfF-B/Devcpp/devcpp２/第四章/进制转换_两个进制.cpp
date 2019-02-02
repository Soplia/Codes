/*
	Subject:进制转换_两个进制 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-3-2 
	Date_Begin:11/01/17 19:52
	Date_End:11/01/17 20:35
*/
#include <stdio.h>

int myPow(int a,int b)
{
	int ans=1;
	for(int i=1;i<=a;i++)
		ans*=b;
	return ans;
}
int main()
{
	int a,b;
	char n[20];
	int buf1[20];
	int buf2[20];
	int size,size1;
	//定义c作为权值 
	int c=1; 
	while(scanf("%d%s%d",&a,n,&b)!=EOF)
	{
		//printf("%d,%s,%d",a,n,b);
		size=0;
		size1=0;
		int dec=0;
		
		for(;n[size]!=0;size++)
			if(n[size]>='A'&&n[size]<='F')
				buf1[size]=n[size]-55;
			else if(n[size]>='a'&&n[size]<='f')
				buf1[size]=n[size]-87;
			else 
				buf1[size]=n[size]-'0';
			
			
		for(int i=size-1;i>=0;i--)
		{
		//	printf("%d ",buf1[i]);
			//dec+=buf1[i]*myPow(size-1-i,a);
		//	printf("%d \n",dec);
			dec+=buf1[i]*c;
			c*=a;
		}
			
			
		do
		{
			buf2[size1++]=dec%b;
			dec/=b;
		}while(dec!=0);
		//printf("\n");
		for(int i=size1-1;i>=0;i--)
			printf("%d",buf2[i]);
		printf("\n");
	}
	return 0;
}
/*
测试数据
样例输入
15 Aab3 7
样例输出
210306
*/
























