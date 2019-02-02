/*
Subject:N
ID:4.12
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 10:14
Result:	
1   Runtime Error	908 kb	0 ms	0/10
2	Wrong Answer	912 kb	10 ms	0/10
3	Wrong Answer	912 kb	10 ms	0/10
4	Wrong Answer	912 kb	10 ms	0/10
5	Wrong Answer	912 kb	80 ms	0/20
6	Wrong Answer	912 kb	100 ms	0/20
7	Wrong Answer
EndTime:
*/
#include <stdio.h>
#define N 2000

typedef struct bigI
{
	int digit[N];
	int size;
}bigI;

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
	if(!flag)
		printf("0");
	printf("\n");
}

void init(bigI *t)
{
	for(int i=0;i<N;i++)	
		t->digit[i]=0;
	t->size=0;
}

bigI * multiple(int x)
{
	bigI temp,*t=&temp;
	init(t);
	t->digit[t->size++]=1;
	
	if(x==0||x==1)
		return t;
	
	int sum;
	int carry=0;
	
	for(int i=2;i<=x;i++)
	{
		for(int j=0;j<t->size;j++)
		{
			sum=t->digit[j]*i+carry;
			carry=sum/10000;
			t->digit[j]=sum%10000;
		}
		
		if(carry!=0)
			t->digit[t->size++]=carry;
			
		carry=0;
	}
	
	return t;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bigI *t;
		t=multiple(n);
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


