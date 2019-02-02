/*
Subject:BST
ID:3.5
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 16:31
Result:Accepted
EndTime:05/02/17 16:55
*/
#include <stdio.h>
#define N 200

typedef struct node
{
	struct node *lchild,*rchild;
	int d;
}node;

node Tree[N];
int loc;
int array[N];

void preOrder(node *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->d);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}

void inOrder(node *t)
{
	if(t!=NULL)
	{
		inOrder(t->lchild);
		printf("%d ",t->d);
		inOrder(t->rchild);
	}
}

void postOrder(node *t)
{
	if(t!=NULL)
	{
		postOrder(t->lchild);
		postOrder(t->rchild);
		printf("%d ",t->d);
	}
}

node *create()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}

node *build(node *a,int x)
{
	if(a==NULL)
	{
		a=create();
		a->d=x;
		return a;
	}
		
	else if(x>a->d)
		a->rchild=build(a->rchild,x);
	else if(x<a->d)
		a->lchild=build(a->lchild,x);
		
	return a;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		loc=0;
		int temp;
		node *t=NULL;
		while(n--)
		{
			scanf("%d",&temp);
			t=build(t,temp);
		}
		preOrder(t);
		printf("\n");
		inOrder(t);
		printf("\n");
		postOrder(t);
		printf("\n");
	}
	return 0;
}
/*
InputData:
5 
1 6 5 9 8
OutputData:
1 6 5 9 8
1 5 6 8 9
5 8 9 6 1
*/

