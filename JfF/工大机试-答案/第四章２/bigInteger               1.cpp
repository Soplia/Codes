/*
Subject:bigInteger
ID:4.11
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 21:59
Result:Wrong Answer
EndTime:
*/

#include <stdio.h>
#include <string.h>
#define N 10000

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
	
void output(bigI *t)
{
	int flag=0;
	for(int i=t->size-1;i>=0;i--)
	{
		if(!flag&&!t->digit[i])
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
	
//void output(bigI *t)
//{
//	for(int i=t->size-1;i>=0;i--)
//		if(i==t->size-1)
//			printf("%d",t->digit[i]);
//		else
//			printf("%04d",t->digit[i]);
//	printf("\n");
//}

void set(bigI *t,char a[])
{
	init(t);
	int len=strlen(a);
	int pow=1;
	int j=0;
	int temp=0;
	
	for(int i=len-1;i>=0;i--)
	{
		temp+=(a[i]-'0')*pow;
		pow*=10;
		j++;
		if(j==4||i==0) 
		{
			t->digit[t->size++]=temp;
			pow=1;
			temp=0;
			j=0;
		}
	}
}
	
bigI *add (bigI *f,bigI *e)
{
	int carry=0; 
	bigI temp,*t;
	t=&temp;
	init(t);
	
	for(int i=0;i<f->size||i<e->size;i++)
	{
		int a=f->digit[i]+e->digit[i]+carry;
		carry=a/10000;
		a%=10000;
		t->digit[t->size++]=a;
		
	}
	
	if(carry!=0)
		t->digit[t->size++]==carry;
		
	return t;
}

int main()
{
	char a[N],b[N];
	while(scanf("%s%s",a,b)!=EOF)
	{
		bigI aa;
		set(&aa,a);
		bigI bb;
		set(&bb,b);
		bigI*t=add(&aa,&bb);
		output(t);
	}
	return 0;
}

/*
InputData:
2 6
10000000000000000000 10000000000000000000000000000000
OutputData:
8
10000000000010000000000000000000
*/





