/*
Subject:BT
ID:3.4
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 15:52
Result:Accepted
EndTime:05/02/17 16:17
*/
#include <stdio.h>
#include <string.h>
#define N 50

typedef struct node
{
	struct node *lchild,*rchild;
	char d;
}node;

node Tree[N];
char a[N],b[N];
int loc;

node *create()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}

node *build(int s1,int e1,int s2,int e2)
{
	node *t=create();
	t->d=a[s1];
	int pos;
	for(int i=s2;i<=e2;i++)
		if(a[s1]==b[i])
		{
			pos=i;
			break;
		}
	if(pos!=s2)
		t->lchild=build(s1+1,s1+(pos-s2),s2,pos-1);
		
	if(pos!=e2)
		t->rchild=build(s1+(pos-s2)+1,e2,pos+1,e2);
	return t;
}

void postOrder(node *t)
{
	if(t!=NULL)
	{
		postOrder(t->lchild);
		postOrder(t->rchild);
		printf("%c",t->d);
	}
}

int main()
{
	while(scanf("%s%s",a,b)!=EOF)
	{
		loc=0;
		int len1=strlen(a);
		int len2=strlen(b);
		
		//printf("%d_%dHello\n",len1,len2);
		node *t=build(0,len1-1,0,len2-1);
		//printf("World\n");
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

