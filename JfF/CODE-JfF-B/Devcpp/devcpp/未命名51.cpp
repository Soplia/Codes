//�ñ�β��ӷ���д��������һ���������������
//ѧ�������ݣ�ֱ�������ѧ���ǡ�0��Ϊֹ��

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
			q=head=a;//�������q���и�ֵ����ô��ָ��ľͲ�֪���������λ�á�
					//�е��˻��ʣ����治���Ѿ�������ֵΪhead������ʵ����
					//�ı�����q=NULL�����˶��ѡ������ǲ��ܹ��������еġ� 
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







