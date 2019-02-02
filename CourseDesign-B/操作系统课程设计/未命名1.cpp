#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Status;
//�ڵ����� 
typedef struct list_node
{
	int numOfNode;//�ڵ��� ��Ҳ�����̿�Ĵ�С�� 
	int size;//�ڵ��С��Ҳ�����̿�Ĵ�С�� 
	int leftSize;//�ڵ�ʣ��Ĵ�С��Ҳ�����̿�ʣ��Ĵ�С�� 
	struct list_node *next;//ָ����һ���ڵ��ָ�� 
}Node;
//Ҫ��������̿�ڵ� 
typedef struct block_node
{
	int numOfBlock;//��ţ�Ҳ���ǽ�Ҫ��������̿��ţ� 
	int size;//�ļ���С 
	int begin;//���̿��п�ʼ��λ�� 
	//Node *current;//��ǰ�̿�ָ�� 
	int current_size;
	int current_leftSize;
	
	struct block_node *next;
}Block;
//�����̿������ͷָ�� 
Node *head_node=NULL;
//ѭ����Ӧʱ�ĵ�ǰָ�� 
Node *next_node=NULL;
//������������ļ���ͷָ�� 
Block *head_block=NULL;
//����һ���ڵ� 
Node * create_node(int xuhao,int daxiao)
{
	Node *temp=new Node();
	temp->numOfNode=xuhao;
	temp->size=daxiao;
	temp->leftSize=daxiao;
	temp->next=NULL;
	return temp;
}
//����һ���ڵ� 
Block * create_block(int xuhao,int daxiao,int kaishi,Node *a)
{
	Block * temp=new Block();
	temp->numOfBlock=xuhao;
	temp->size=daxiao;
	temp->begin=kaishi;
	//����ط���Ϊa��ָ�����Իᷢ��ǳ����������Ϊ
	//û�ж�a���в������Բ���Ӱ�쵽ԭ�����������Բ��ø�Ϊ����� 
	//temp->current=new Block();
	//temp->current=a;
	temp->current_size=a->size;
	temp->current_leftSize=a->leftSize;
	temp->next=NULL;
	return temp;
}
//���ڵ�����������ļ��������� 
void insert_block(Block *temp)
{
	Block *p;
	if(head_block==NULL)
		head_block=temp;
	else
	{
		p=head_block;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}
//���������ڵ㣬��������ʹ�� 
void exchange(Node *a,Node *b)
{
	int num;
	int size;
	int left;
	num=a->numOfNode;
	size=a->size;
	left=a->leftSize;
	a->numOfNode=b->numOfNode;
	a->size=b->size;
	a->leftSize=b->leftSize;
	b->numOfNode=num;
	b->size=size;
	b->leftSize=left;
}
//���̿�Ĵ�С����������Ҫ������worst_fit����㷨�� 
void sort_size()
{
	if(head_node==NULL)
		cout<<"The list is empty!"<<endl;
	else
	{
		int size=100;
		Node *temp=head_node;
		for(int i=0;i<size-1;i++)
		{
			temp=head_node;
			for(int j=0;j<size-1-i;j++)
			{
				if(temp->size<temp->next->size)
					exchange(temp,temp->next);
				temp=temp->next;
			}
		}
			
	}
}
//�����̿�����
//�ٶ�һ����100���̿飬�̿��С��10 ��ʼÿ���𲽼�10 �������һ����1000 
void createList()
{
	int i=0;
	int size=10;
	Node *p;
	while(i<100)
	{
		Node *temp=create_node(i,size);
		if(head_node==NULL)
			head_node=temp;
		else
			p->next=temp;
		p=temp;
		i++;
		size+=10;
	}
}
//��ʾ�ڵ� 
void show_node(Node *temp)
{
	cout<<"�����:"<<temp->numOfNode<<"  ";
	cout<<"��С��:"<<temp->size<" ";
	cout<<"ʣ���С��:"<<temp->leftSize<<endl;
}
//��ʾ�ڵ� 
void show_block(Block *temp)
{
	
	cout<<"�ļ���С��: "<<temp->size<"  ";
	cout<<"�̿����: "<<temp->numOfBlock<<"  ";
	cout<<"�̿�������: "<<temp->current_size<<"  ";
	cout<<"��ʼλ����: "<<temp->begin<<"  ";
	cout<<"�̿�ʣ��������:"<<temp->current_leftSize<<endl;
}
//��ʾ���� 
void show_list()
{
	Node *temp;
	if(head_node==NULL)
		cout<<"The list is empty!"<<endl;
	else
	{
		temp=head_node;
		while(temp!=NULL)
		{
			show_node(temp);
			temp=temp->next;
		}
	}
}
//��ʾ���� 
void show_block()
{
	Block *temp;
	if(head_block==NULL)
		cout<<"The list is empty!"<<endl;
	else
	{
		temp=head_block;
		while(temp!=NULL)
		{
			show_block(temp);
			temp=temp->next;
		}
	}
}
//�����Ӧ��������״���Ӧʱһ���ġ� 
Status Best_fit(int request)
{
	Node *temp;
	if(head_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}
	else
	{
		temp=head_node;
		//�ҵ�������Ľڵ� 
		while(temp!=NULL&&temp->leftSize<request)
			temp=temp->next;
		if(temp==NULL)
			return 0;
		else
		{
			int temp_leftSize=temp->leftSize;
			temp->leftSize=temp->leftSize-request;
			Block *b=create_block(temp->numOfNode,request,temp->size-temp_leftSize,temp);
			insert_block(b);
		}
	}
	return 1;
}
//���Ӧ 
Status Worst_fit(int request)
{
	Node *temp;
	if(head_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}
	else
	{
		sort_size();
		temp=head_node;
		while(temp!=NULL&&temp->leftSize<request)
			temp=temp->next;
		if(temp==NULL)
			return 0;
		else
		{
			int temp_leftSize=temp->leftSize;
			temp->leftSize=temp->leftSize-request;
			Block *b=create_block(temp->numOfNode,request,temp->size-temp_leftSize,temp);
			insert_block(b);
			
		}
	}
	return 1;
}
//�״���Ӧ 
Status first_fit(int request)
{
	Node *temp;
	if(head_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}
	else
	{
		temp=head_node;
		while(temp!=NULL&&temp->leftSize<request)
			temp=temp->next;
		if(temp==NULL)
			return 0;
		else
		{
			int temp_leftSize=temp->leftSize;
			temp->leftSize=temp->leftSize-request;
			Block *b=create_block(temp->numOfNode,request,temp->size-temp_leftSize,temp);
			insert_block(b);
		}
	}
	return 1;
}
//ѭ����Ӧ 
Status next_fit(int request)
{
	if(next_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}	
	else
	{
		while(next_node!=NULL&&next_node->leftSize<request)
			next_node=next_node->next;
		if(next_node->next==NULL)
			next_node=head_node;
		else 
		{	
			int temp_leftSize=next_node->leftSize;
			next_node->leftSize=next_node->leftSize-request;
			Block *b=create_block(next_node->numOfNode,request,next_node->size-temp_leftSize,next_node);
			insert_block(b);
			
		}	
	}
	return 1;
}

int main()
{
	createList();
	next_node=head_node;
	
	int i=1;
	while(i<=10)
	{
		int size;
		cout<<"Input the request:"<<endl;
		cin>>size;
		next_fit(size);
		show_block();
		cout<<"Input the request:"<<endl;
		cin>>size;
		first_fit(size);
		show_block();
		cout<<"Input the request:"<<endl;
		cin>>size;
		Best_fit(size);
		show_block();
		cout<<"Input the request:"<<endl;
		cin>>size;
		Worst_fit(size);
		show_block();
		i++;
	}	
	return 0;
}

















