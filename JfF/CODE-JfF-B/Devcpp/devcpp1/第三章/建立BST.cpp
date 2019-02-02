/*
	Subject:建立BST 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:3-4-1
	Date_Begin:11/01/17 10:34
	Date_End:
*/
#include <stdio.h>

struct tree 
{
	tree *lChild;
	tree *rChild;
	int data;
}Tree[50];

int loc;

tree * create()
{
	Tree[loc].lChild=Tree[loc].rChild=NULL;
	return &Tree[loc++];
}

void preOrder(tree *t)
{
	printf("%d ",t->data);
	if(t->lChild!=NULL)
		preOrder(t->lChild);
	if(t->rChild!=NULL)
		preOrder(t->rChild);
}

void inOrder(tree *t)
{
	if(t->lChild!=NULL)
		inOrder(t->lChild);
	printf("%d ",t->data);
	if(t->rChild!=NULL)
		inOrder(t->rChild);
}

void postOrder(tree *t)
{
	if(t->lChild!=NULL)
		postOrder(t->lChild);
	if(t->rChild!=NULL)
		postOrder(t->rChild);
	printf("%d ",t->data);
}

tree *buildBST(tree *t ,int x)
{
	if(t==NULL)
	{
		t=create();
		t->data=x;
		return t;
	}
	else if(t->data>x)
		t->lChild=buildBST(t->lChild,x);
	else 
		t->rChild=buildBST(t->rChild,x);
	return t;
}

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		int temp;
		tree *t=NULL;
		loc=0;
		for(int i=0;i<size;i++)
		{
			scanf("%d",&temp);
			t=buildBST(t,temp);
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
测试数据
5 
1 6 5 9 8
*/














