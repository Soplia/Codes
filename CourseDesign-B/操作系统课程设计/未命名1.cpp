#include <iostream>
#include <cstdlib>
using namespace std;
typedef int Status;
//节点类型 
typedef struct list_node
{
	int numOfNode;//节点编号 （也就是盘块的大小） 
	int size;//节点大小（也就是盘块的大小） 
	int leftSize;//节点剩余的大小（也就是盘块剩余的大小） 
	struct list_node *next;//指向下一个节点的指针 
}Node;
//要被分配的盘块节点 
typedef struct block_node
{
	int numOfBlock;//编号（也就是将要被分配的盘块编号） 
	int size;//文件大小 
	int begin;//在盘块中开始的位置 
	//Node *current;//当前盘块指针 
	int current_size;
	int current_leftSize;
	
	struct block_node *next;
}Block;
//整个盘块的链表头指针 
Node *head_node=NULL;
//循环适应时的当前指针 
Node *next_node=NULL;
//整个待分配的文件的头指针 
Block *head_block=NULL;
//创建一个节点 
Node * create_node(int xuhao,int daxiao)
{
	Node *temp=new Node();
	temp->numOfNode=xuhao;
	temp->size=daxiao;
	temp->leftSize=daxiao;
	temp->next=NULL;
	return temp;
}
//创建一个节点 
Block * create_block(int xuhao,int daxiao,int kaishi,Node *a)
{
	Block * temp=new Block();
	temp->numOfBlock=xuhao;
	temp->size=daxiao;
	temp->begin=kaishi;
	//这个地方因为a是指正所以会发生浅拷贝但是因为
	//没有对a进行操作所以不会影响到原来的链表，所以不用改为深拷贝了 
	//temp->current=new Block();
	//temp->current=a;
	temp->current_size=a->size;
	temp->current_leftSize=a->leftSize;
	temp->next=NULL;
	return temp;
}
//讲节点插入待分配的文件的链表中 
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
//交换两个节点，在排序中使用 
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
//按盘块的大小进行排序，主要是用于worst_fit这个算法中 
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
//创建盘块链表
//假定一共有100个盘块，盘块大小从10 开始每次逐步加10 所以最后一个是1000 
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
//显示节点 
void show_node(Node *temp)
{
	cout<<"序号是:"<<temp->numOfNode<<"  ";
	cout<<"大小是:"<<temp->size<" ";
	cout<<"剩余大小是:"<<temp->leftSize<<endl;
}
//显示节点 
void show_block(Block *temp)
{
	
	cout<<"文件大小是: "<<temp->size<"  ";
	cout<<"盘块号是: "<<temp->numOfBlock<<"  ";
	cout<<"盘块容量是: "<<temp->current_size<<"  ";
	cout<<"起始位置是: "<<temp->begin<<"  ";
	cout<<"盘块剩余容量是:"<<temp->current_leftSize<<endl;
}
//显示链表 
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
//显示链表 
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
//最佳适应，这个和首次适应时一样的。 
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
		//找到待分配的节点 
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
//最坏适应 
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
//首次适应 
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
//循环适应 
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

















