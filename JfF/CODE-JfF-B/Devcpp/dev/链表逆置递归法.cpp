#include <iostream>
#include <iomanip>
using namespace std;
class Node
{
 public:
 	void set(int a);
 	Node();
 	Node(int a);
 	void show();
 	int data;
 	Node *next;
};
void Node::set(int a)
{
	this->data=a;
	this->next=NULL;
}
Node::Node()
{
	this->set(0);
}
Node::Node(int a)
{
	this->set(a);
}
void Node::show()
{
	cout<<setw(4)<<this->data;
}
class List
{
 public:
 	void createList();
 	void showList();
 	void reserve();
 	Node* reserve(Node *a);
 	Node* contact(Node *a,Node *b);
 	int getSize(Node *a,int b);

 	Node *firstNode;
 	int length;
};
void List::createList()
{
	Node *temp1,*temp2;
	for(int i=1;i<11;i++)
	{
		temp1=new Node(i);
		if(this->firstNode==NULL)
			this->firstNode=temp1;
		else
			temp2->next=temp1;
		temp2=temp1;
		this->length++;
	}
}
void List::showList()
{
	Node *temp=this->firstNode;
	while(temp!=NULL)
	{
		temp->show();
		temp=temp->next;
	}
}
void List::reserve()
{
	this->firstNode=this->reserve(this->firstNode);
}
Node *List::reserve(Node *a)
{
	if(a==NULL)
		return NULL;
	else
	{
		Node *head,*tail;
		head=a;
		tail=a->next;
		head->next=NULL;
		return this->contact(reserve(tail),head);
	}
}
Node *List::contact(Node *a,Node *b)
{
	if(a==NULL)
		return b;
	else
	{
		a->next=contact(a->next,b);
		return a;
	}
}
//递归求解链表的长度 
int List::getSize(Node *temp,int sum)
{
	if(temp==NULL)
		return sum;
	else
		return getSize(temp->next,sum+1);
}

int main()
{
	List *first=new List();
	first->createList();
	cout<<"The first:"<<endl;
	first->showList();
	cout<<endl;
	first->reserve();
	cout<<"The second:"<<endl;
	first->showList();
	cout<<endl;
	cout<<"The length of the list is:"<<first->length<<endl;
	cout<<"The length of the list is:"<<first->getSize(first->firstNode,0)<<endl;
	return 0;
}





















