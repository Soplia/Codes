/*
	Subject:�߾���_����_�߾���*�;��� 
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
	
	//��ε�������һ��С���������Բ���Ҫʹ���ַ������� 
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
	//��֪��Ϊʲôʹ��*=���� 
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
	//���Ҫʹ�ö������ݣ���Ҫ��д������������� 
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
��������
��������
4
5
15
�������
24
120
1307674368000
*/


























