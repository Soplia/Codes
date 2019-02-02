/*
Subject:2010_2
ID:2010_2
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 20:45
Result:Accepted
EndTime:06/02/17 21:48
*/
#include <stdio.h>
#define N 100

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
	for(int i=t->size-1;i>=0;i--)
		if(i==t->size-1)
			printf("%d",t->digit[i]);
		else
			printf("%04d",t->digit[i]);
	printf("\n");
}

//void check(bigI *s,bigI *e)
//{
//	printf("ans:\n");
//	output(s);
//	printf("term:\n");
//	output(e);
//}

void add(bigI *t,int x)
{
	int carry=0,ans;
	
	for(int i=0;i<t->size;i++)
	{
		if(i==0)
			ans=carry+x+t->digit[i];
		else
			ans=t->digit[i]+carry;
		
		t->digit[i]=ans%10000;
		carry=ans/10000;
		if(!carry)
			break;
	}
	if(carry)
		t->digit[t->size++]=carry;
}

void add2(bigI *t,bigI *tt)
{
	int carry=0;
	for(int i=0;i<t->size||i<tt->size;i++)
	{
		int ans=carry+t->digit[i]+tt->digit[i];
		if(i>=t->size)
			t->digit[t->size++]=ans%10000;
		else
			t->digit[i]=ans%10000;
			
		carry=ans/10000;
	}
	if(carry)
		t->digit[t->size++]=carry;
}

void mul(bigI *t,int x)
{
	int carry=0;
	for(int i=0;i<t->size;i++)
	{
		int ans=carry+x*t->digit[i];
		t->digit[i]=ans%10000;
		carry=ans/10000;
	}
	if(carry)
		t->digit[t->size++]=carry;
}

int main()
{
	int a,n;
	while(scanf("%d%d",&a,&n)!=EOF)
	{
		bigI ans,term;
		set(&ans,0);
		set(&term,0);
		
		//check(&ans,&term);
		
		for(int i=1;i<=n;i++)
		{
			mul(&term,10);
			add(&term,a);
			add2(&ans,&term);
			//printf("‘æ%dŽŸ\n",i);
			//check(&ans,&term);
		}
			
		output(&ans);
	}
	return 0;
}
/*
InputData:
1 10
OutputData:
1234567900
*/

