/*
	Name: Link
	Complier: Devcpp
	Date: 10/12/14 15:02 Wednesday
	Description: The simply operations of the Link
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;
int numberOfNode=0;
#define Len sizeof(Node)
Node *createNode();
Node *creareNode(int temp);
Node *createLink();
void outputOne(Node *p);
void outputAll(Node *head);
Node *removeNode(Node *head);
Node *insertNode(Node *head);
Node *modifyNode(Node *head);
int saveFile(Node *head);
Node *loadFile();
void menu();
Node *createNode()
{
	Node *temp;
	temp=(Node *)malloc(Len);
	printf("Please enter a digit for the node:\n");
	scanf("%d",&temp->data);
	getchar();
	temp->next=NULL;
	return temp;
}
Node *createNode(int tempDigit)
{
	Node *temp;
	temp=(Node*)malloc(Len);
	temp->data=tempDigit;
	temp->next=NULL;
	return temp;
}
Node *createLink()
{
	char c='Y';
	Node *head=NULL;
	Node *q,*p;
	while(c=='Y'||c=='y')
	{
		p=createNode();
		if(head==NULL)
			head=p;
		else
			q->next=p;
		q=p;
		numberOfNode++;
		printf("Contine to create the link(Y/N)?\n");
		c=getchar();
	}
	return head;
}
void outputOne(Node *p)
{
	printf("The data of the link is:%d\n",p->data);
}
void outputAll(Node *head)
{
	if(head==NULL)
		printf("Sorry,the link is empty!\n");
	else
	{
		Node *temp;
		temp=head;
		while(temp!=NULL)
		{
			outputOne(temp);
			temp=temp->next;
		}
	}
}
Node *removeNode(Node *head)
{
	if(head==NULL)
		printf("The link is empty,can't do this operation!\n");
	else
	{
		Node *p,*q;
		char c='y';
		char d='y';
		int digit;
		while(c=='y'||c=='Y')
		{
			p=head;
			printf("Please input the data of the node you want to remove:\n");
			scanf("%d",&digit);
			getchar();
			while(p->data!=digit&&p->next!=NULL)
			{
				q=p;
				p=p->next;
			}
			if(p->data==digit)
			{
				outputOne(p);
				printf("Are you sure to delete it?(Y/N)?\n");
				d=getchar();
				getchar();
				if(d=='y'||d=='Y')
				{
					if(p==head)
						head=p->next;
					else
						q->next=p->next;
					delete p;
					numberOfNode--;
					printf("This node have been deleted!\n");
				}
				else
					printf("Have cancled the operation!\n");
			}
			else
				printf("Sorry,there don't include this node!\n");
			printf("Contine to delete another node(Y/N)?\n");
			c=getchar();
		}
	}
	return head;
}
Node *insertNode(Node *head)
{
	char c='y';
	Node *p,*q,*p0;
	int pos;
	while(c=='y'||c=='Y')
	{
		p0=createNode();
		if(head==NULL)
			head=p0;
		else
		{
			p=head;
			while(p->data<p0->data&&p->next!=NULL)
			{
				q=p;
				p=p->next;
			}
			if(p->data>=p0->data)
			{
				if(p==head)
					head=p0;
				else
					q->next=p0;
					p0->next=p;	
			}
			else
			{
				printf("Insert by defult!\n");
				p->next=p0;
			}
		}
		printf("Continue to insert(Y/N)?\n");	
		c=getchar();
		numberOfNode++;
	}
	return head;
}
Node *modifyNode(Node *head)
{
	if(head==NULL)	
		printf("The link is empty,can't do this job!\n");
	else
	{
		char c='y';
		char d='y';
		int digit;
		while(c=='y'||c=='Y')
		{
			printf("Please input the data that you will modify:\n");
			scanf("%d",&digit);
			getchar();
			Node *p,*q;
			p=head;
			while(p->data!=digit&&p->next!=NULL)
				p=p->next;
			if(p->data==digit)
			{
				 outputOne(p);
				 printf("Are continue to modify it(y/n)?\n");
				 d=getchar();
				 if(d=='y'||d=='Y')
				 {
				 	printf("Please input the digit that you will assign to the node:\n");
				 	scanf("%d",&p->data);
				 	getchar();
				 	printf("This node had been modified!\n");
				 }
				 else
				 	printf("Had give up this operation!\n");
			}
			else
				printf("There isn't include this node!\n");
			printf("Continue to modify another node!(y/n)?\n");
			c=getchar();
		}
	}
	return head;
}
int saveFile(Node *head)
{
	if(head==NULL)
	{
		printf("The link is empty,can't do this operation!\n");
		return 0;
	}
	Node *p;
	p=head;
	FILE *file;
	if((file=fopen("Infor.txt","w"))==NULL)
	{
		printf("The caeation of the file is fail!\n");
		return 0;
	}
	fprintf(file,"节点数是:%d\n",numberOfNode);
	while(p!=NULL)
	{
		fprintf(file,"%d\n",p->data);
		p=p->next;
	}
	printf("The file had been saved!\n\n");
	return 1;
}
Node* loadFile()
{
	Node *head=NULL;
	Node *p,*q;
	FILE *file;
	int acount;
	if((file=fopen("Infor.txt","r"))==NULL)
	{
		printf("The creation of the file is fail!\n");
		exit(0);
	}
	fscanf(file,"节点数是:%d\n",&acount);
	int temp;
	for(int i=1;i<=acount;i++)
	{
		fscanf(file,"%d\n",&temp);
		p=createNode(temp);
		if(head==NULL)
			head=p;
		else
			q->next=p;
		q=p;
	} 
	printf("录入文件完成了!\n\n");
	return head;
}
void menu()
{
	printf("\t---------------------------------------------------------\n");
	printf("\t******\t\tWelcome To The Link!\t\t   ******\n");
	printf("\t******\t1.Create			2.Output   ******\n");
	printf("\t******\t3.Delete			4.Insert   ******\n");
	printf("\t******\t5.Modify			6.Save     ******\n");
	printf("\t******\t7.Load  			0.Exit     ******\n");
	printf("\t---------------------------------------------------------\n");
	int selection;
	Node *head=NULL;
	while(1)
	{
		printf("\nPlease choose the operation that you want to do:\n");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:head=createLink();break;
			case 2:outputAll(head);break;
			case 3:head=removeNode(head);break;
			case 4:head=insertNode(head);break;
			case 5:head=modifyNode(head);break;
			case 6:saveFile(head);break;
			case 7:head=loadFile();break;
			case 0:printf("Thanks!\n");exit(0);break;
			default:printf("Please input the eagle selection!\n");break;
		}
	}
}
int main()
{
	menu();
	return 0;
}
























