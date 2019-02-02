/*
Subject:Judge BST
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 17:43
Result:Wrong
EndTime:
*/
#include <stdio.h>
#include <string.h>
#define N 400

typedef struct node
{
	struct node *lchild,*rchild;
	char d;
}node;

node Tree[N];
char *sum,a[N],b[N];
int *size;
int loc;

void preOrder(node *t)
{
	if(t!=NULL)
	{
		sum[(*size)++]=t->d;
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}

void inOrder(node *t)
{
	if(t!=NULL)
	{
		inOrder(t->lchild);
		sum[(*size)++]=t->d;
		inOrder(t->rchild);
	}
}

void postOrder(node *t)
{
	if(t!=NULL)
	{
		postOrder(t->lchild);
		postOrder(t->rchild);
		sum[(*size)++]=t->d;
	}
}

node *create()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}

node *insert(node *t,char x)
{
	if(t==NULL)
	{
		t=create();
		t->d=x;
		return t;
	}
	else if((t->d)-'0'<x-'0')
		t->rchild=insert(t->rchild,x);
	else if((t->d)-'0'>x-'0')
		t->lchild=insert(t->lchild,x);
		
	return t;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		getchar();
		loc=0;
		gets(a);
		node *t1=NULL;
		for(int i=0;i<strlen(a);i++)
			t1=insert(t1,a[i]);
		
		int asize=0;
		size=&asize;
		sum=a;
		preOrder(t1);
		inOrder(t1);
		a[asize]=0;
		while(n--)
		{
			gets(b);
			node *t2=NULL;
			for(int i=0;i<strlen(a);i++)
				t2=insert(t2,a[i]);
			
			int bsize=0;
			size=&bsize;
			sum=b;
			preOrder(t2);
			inOrder(t2);
			b[bsize]=0;
			printf("%s\n",!strcmp(a,b)?"YES":"NO");
		}
	
	}
	return 0;
}
/*
InputData:
2
567432
543267
576342
0
OutputData:
YES
NO
*/

