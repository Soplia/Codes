#include <stdio.h>
#include <string.h>
#define N 100

typedef struct node
{
	char data;
	struct node *lChild;
	struct node *rChild;	
} Node;

int size;
Node arr[N];
char str1[N],str2[N];

Node *create()
{
	arr[size].lChild=arr[size].rChild=NULL;
	return &arr[size++]	;
}

void postOrder(Node *t)
{
	if(t->lChild!=NULL)
		postOrder(t->lChild);
	if(t->rChild!=NULL)
		postOrder(t->rChild);
	printf("%c",t->data);
}

Node *build(int s1,int e1,int s2,int e2)
{
	Node *ret=create();
	ret->data=str1[s1];
	int rootId;
	for(int i=s2;i<=e2;i++)
		if(str1[s1]==str2[i])
		{
			rootId=i;
			break;
		}
		
	if(rootId!=s2)
		ret->lChild=build(s1+1,s1+(rootId-s2),s2,rootId-1);
	if(rootId!=e2)
		ret->rChild=build(s1+(rootId-s2)+1,e1,rootId+1,e2);
	
	return ret;
}

int main()
{
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		size=0;
		Node *t=build(0,strlen(str1)-1,0,strlen(str2)-1);
		postOrder(t);
		printf("\n");
	}
	return 0;
}


