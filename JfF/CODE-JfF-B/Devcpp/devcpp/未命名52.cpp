//编写函数删除链表中的结点。
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
}Node;

void display(Node *a)
{
	Node *b=a;
	if(b==NULL)
		printf("The list is NULL!\n");
	else
		while(b!=NULL)
		{
			printf("%d\n",b->num);
			b=b->next;
		}
}

Node* createNode()
{
	int b;
	printf("Input a NUM:\n");
	scanf("%d",&b);
	Node *a=(Node *)malloc(sizeof(Node));
	a->num=b;
	a->next=NULL;
	return a;
}

Node *createList(int size)
{
	Node *head=NULL,*a,*b;
	for(int i=0;i<size;i++)
	{
		a=createNode();
		if(head==NULL)
			b=head=a;
		else
		{
			b->next=a;
			b=a;
		}
	}
	return head;
}

Node *rid(Node *a)
{
	Node *q,*p;
	if(a==NULL)
		printf("The list is NUll!\n");
	else
	{
		int aim;
		printf("Intput the num that you will delete:\n"); 
		scanf("%d",&aim);
		p=a;
		int flag=false;
		while(p->next!=NULL)
		{
			if(p->num==aim)
				if(p==a)//删除头结点 
				{
					flag=true;
					a=p->next;
					free(p);
					printf("Delete this head node successfully!\n");
				}
				else//删除中间节点或者是尾节点
				{
					flag=true;
					q->next=p->next;
					free(p);
					printf("Delete this middle node successfully!\n");
				}
			q=p;
			p=p->next; 
		}
		if(!flag)
			printf("Can't find this node!\n");
	}
	return a;
}

int main()
{
	Node *head;
	head=createList(4);
	display(head);
	for(int i=0;i<3;i++)
	{
		head=rid(head);
		display(head);
	}
	return 0;
}

