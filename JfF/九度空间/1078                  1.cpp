/*
Subject:二叉树遍历 
ID:1078
Complier:Devcpp
Author:JiaruiXie
StartTime:18/03/17 07:40
Result:Accepted
EndTime:18/03/17 08:33
*/

#include <stdio.h>
#include <string.h>
#define N 100

int size;
char str1[N],str2[N];

typedef struct node
{
	char data;
	struct node *lChild;
	struct node *rChild; 
}Node;

Node arr[N];

Node *create()
{
	arr[size].lChild=arr[size].rChild=NULL;
	return &arr[size++];
}

void postOrder(Node *t)
{
	if(t->lChild!=NULL)
		postOrder(t->lChild);
	if(t->rChild!=NULL)
		postOrder(t->rChild);
	printf("%c",t->data);
}

//这个递归建立树还是不会写 
Node *createT(int s1,int e1,int s2,int e2)
{
	Node *t=create();
	t->data=str1[s1];
	
	int rootId;
	for(int i=s2;i<=e2;i++)
		if(str2[i]==str1[s1])
		{
			rootId=i;
			break;
		}
	
	if(rootId!=s2)
		t->lChild=createT(s1+1,s1+(rootId-s2),s2,rootId-1);
	if(rootId!=e2)
		t->rChild=createT(s1+(rootId-s2)+1,e1,rootId+1,e2);
		
	return t;
}

int main()
{
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		size=0;
		int L1=strlen(str1);
		int L2=strlen(str2);
		Node *t=createT(0,L1-1,0,L2-1);
		postOrder(t);
		printf("\n");
	}
	return 0;
}

/*
InputData:
ABC
BAC
FDXEAG
XDEFAG
OutputData:
BCA
XEDGAF
*/

