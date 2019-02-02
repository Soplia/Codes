/*
	Subject:�߾���_����_�ӷ� 
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
	//���г�ʼ�� 
	void init()
	{
		size=0;
		for(int i=0;i<len;i++)
			digit[i]=0;
	}
	
	//���ַ�������ȡ������
	void set(char *a)
	{
		//���Ƚ��г�ʼ�� 
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
	
	//���
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
		//����ط�����֮���п��ܲ���1�� 
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
//		printf("�ڴ����ʧ�ܣ�\n");
//		goto Solve;
//	}
//	else if(a!=NULL)
//		printf("�ڴ�a����ɹ�\n");
//		
//	char *b=(char *)malloc(sizeof(char)*len);
//	if(b==NULL)
//	{
//		printf("�ڴ����ʧ�ܣ�\n");
//		goto Solve;
//	}
//	else if(b!=NULL)
//		printf("�ڴ�b����ɹ�\n");
		
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
	 
//	Solve://ֻҪ�ڴ�δ�ɹ����䣬������ʹ��malloc������ڴ�ռ䶼�ͷŵ��� 
//		if(a!=NULL)
//		{
//			free(a);
//			printf("�Ѿ��ͷ�a\n");
//		}
//		if(b!=NULL)
//		{
//			free(b);
//			printf("�Ѿ��ͷ�b\n");
//		}
			
			
	return 0;
}
/*
��������
��������
2 6
10000000000000000000  10000000000000000000000000000000
�������
8
10000000000010000000000000000000
*/

















