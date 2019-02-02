/*
Subject:¶þ²æÅÅÐòÊ÷ 
ID:1201
Complier:Devcpp
Author:JiaruiXie
StartTime:18/03/17 09:22
Result:Accepted
EndTime:18/03/17 09:47
*/

#include <stdio.h>
#define N 2000

typedef struct node 
{
	int data;
	struct node *lChild;
	struct node *rChild;
}Node;

Node arr[N];
int size;

Node *createN()
{
	arr[size].lChild=arr[size].rChild=NULL;
	return &arr[size++];
}

void preOrder(Node *t)
{
	if(t!=NULL)
	{
		printf("%d ",t->data);
		preOrder(t->lChild);
		preOrder(t->rChild);
	}
}

void inOrder(Node *t)
{
	if(t!=NULL)
	{
		inOrder(t->lChild);
		printf("%d ",t->data);
		inOrder(t->rChild);
	}
}

void postOrder(Node *t)
{
	if(t!=NULL)
	{
		postOrder(t->lChild);
		postOrder(t->rChild);
		printf("%d ",t->data);
	}
}

Node *create(Node *t,int x)
{
	if(t==NULL)
	{
		t=createN();
		t->data=x;
		return t;
	}
	if(x>t->data)
		t->rChild=create(t->rChild,x);
	if(x<t->data)
		t->lChild=create(t->lChild,x);
	
	return t;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		Node *t=NULL;
		int temp;
		size=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			t=create(t,temp);
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

