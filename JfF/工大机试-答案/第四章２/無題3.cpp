/*
Subject:bigInteger
ID:4.11
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 21:59
Result:Accepted
EndTime:05/02/17 09:02
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 1000
using namespace std;


typedef struct Big
{
	int digit[N];
	int size;
	
	void init()
	{
		for(int i=0;i<N;i++)
			digit[i]=0;
		size=0;
	}
	
	void output()
	{
		for(int i=size-1;i>=0;i--)	
			if(i!=size-1)
				printf("%04d",digit[i]);
			else
				printf("%d",digit[i]);
		printf("\n");
	}
	
	void set(char a[])
	{
		init();
		int len=strlen(a);
		for(int i=len-1,j=0,pow=1,temp=0;i>=0;i--)
		{
			j++;
			temp+=(a[i]-'0')*pow;
			pow*=10;
			if(j==4||i==0)
			{
				digit[size++]=temp;
				temp=0;
				pow=1;
				j=0;
			}
		}
	}
	
	Big operator + (Big &a)
	{
		Big temp;
		temp.init();
		
		int carry=0;
		for(int i=0;i<size||i<a.size;i++)
		{
			int t=a.digit[i]+digit[i]+carry;
			temp.digit[temp.size++]=t%10000;
			carry=t/10000;
		}
		if(carry!=0)
			temp.digit[temp.size++]=carry;
		return temp;
	}

}bigI; 

int main()
{
	char a[N],b[N];
	while(scanf("%s%s",a,b)!=EOF)
	{
		bigI aa,bb,cc;
		aa.set(a);
		bb.set(b);
		cc=aa+bb;
		cc.output();
	}
	return 0;
}



