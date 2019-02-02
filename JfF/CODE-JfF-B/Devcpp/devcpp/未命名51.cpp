//用表尾添加法编写函数建立一个链表，存放若干名
//学生的数据，直到输入的学号是“0”为止。

#include <stdio.h>
#include <stdlib.h>

typedef struct stu
{
	int num;
	struct stu *next;
}Node;

Node * createNode()
{
	printf("Input a num:\n");
	int num;
	scanf("%d",&num);
	Node * a=(Node *)malloc(sizeof(Node));
	a->num=num;
	a->next=NULL;
	return a;
}

Node *show(Node *node)
{
	Node *h=node;
	if(h==NULL)
		printf("The List Is Null!\n");
	else
		while(h!=NULL)
		{
			printf("%d\n",h->num);
			h=h->next;
		}
}

Node *createList()
{
	int size=3;
	Node *q;
	Node *head=NULL;
	q=head;
	for(int i=0;i<3;i++)
	{
		Node *a=createNode();
		if(head==NULL)
			q=head=a;//如果不给q进行赋值，那么它指向的就不知道是哪里的位置。
					//有的人会问，上面不是已经给它赋值为head了吗，其实哪里
					//的本质是q=NULL，仅此而已。所以是不能够那样进行的。 
		else
		{
			q->next=a;
			q=a;
		}
	}
	return head;
}
int main()
{
	Node *f=createList();
	show(f);
	return 0;
}







