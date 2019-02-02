/*
	Subject:二叉树 
    Compiler:Devcpp
	Description:给出二叉树的前序和中序序列，要求给出其后序序列 
	Author:JiaruiXie
	Id:3-3-1 
	Date_Begin:11/01/17 09:54
	Date_End:11/01/17 10:14
*/
#include <stdio.h>
#include <string.h>

struct tree
{
	tree *lChild;
	tree *rChild;
	char data;
}Tree[50];

int loc;
char str1[30];
char str2[30];

tree *create()
{
	Tree[loc].lChild=Tree[loc].rChild=NULL;
	return &Tree[loc++];
}

void postOrder(tree *t)
{
	if(t->lChild!=NULL)
		postOrder(t->lChild);
	if(t->rChild!=NULL)
		postOrder(t->rChild);
	printf("%c",t->data);
}

tree * build(int s1,int e1,int s2,int e2)
{
	int rootId=0;
	
	tree *root=create();
	root->data=str1[s1];
	
	for(int i=s2;i<=e2;i++)
		if(root->data==str2[i])
		{
			rootId=i;
			break;
		}
		
	if(rootId>s2)
		root->lChild=build(s1+1,s1+(rootId-s2),s2,rootId-1);
	if(rootId<e2)
		root->rChild=build(s1+(rootId-s2)+1,e1,rootId+1,e2);
		
	return root;
}

int main()
{
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		
		int len1=strlen(str1)-1;
		int len2=strlen(str2)-1;
		
		loc=0;
		
		tree *t=build(0,len1,0,len2);
		
		postOrder(t);
		
		printf("\n");
	}
	return 0;
}
/*
测试数据
ABC
BAC
FDXEAG
XDEFAG
*/




















 
