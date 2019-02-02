/*
Subject:N
ID:4.12
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 10:48
Result:
EndTime:
*/
#include <stdio.h>
#define N 1000

typedef struct bigI
{
	int digit[N];
	int size;
}bigI;

void init(bigI *t)
{
	for(int i=0;i<N;i++)	
		t->digit[i]=0;
	t->size=0;
}

void set(bigI *t,int x)
{
	init(t);
	do
	{
		t->digit[t->size++]=x%10000;
		x/=10000;
	}while(x);
}

void output(bigI *t)
{
	int flag=0;
	for(int i=t->size-1;i>=0;i--)
	{
		if(!flag&&t->digit[i]==0)
			continue;
		if(flag)
			printf("%04d",t->digit[i]);
		else
		{
			printf("%d",t->digit[i]);
			flag=1;
		}
	}
}

bigI *multiple(bigI *t,int x)
{
	int carry=0;
	int sum;
	bigI temp,*te=&temp;
	init(t);
	
	for(int i=0;i<t->size;i++)
	{
		sum=t->digit[i]*x+carry;
		carry=sum/10000;
		te->digit[te->size++]=sum%10000;
	}
	if(carry!=0)
		te->digit[te->size++]=carry;
	return te;
}

int main()
{
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		bigI temp,*t=&temp;
		
		set(t,1);
		//printf("Hello\n");
		for(int i=1;i<=n;i++)	
			t=multiple(t,i);
		//printf("word\n");
			
		output(t);
	}
	
	return 0;
}


/*
InputData:
4
5
15
OutputData:
24
120
1307674368000
*/




















