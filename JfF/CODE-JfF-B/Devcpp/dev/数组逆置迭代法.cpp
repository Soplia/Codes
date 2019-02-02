#include <iostream>
#include <iomanip>
using namespace std;
class Node
{
 public:
 	void set(int a);
 	void show();
 	Node();
 	Node(int a);
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
 	void display();
 	void reserve();
 private:
 	Node *firstNode;
 	int length;
};
void List::createList()
{
	Node *temp1;
	Node *temp2;
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
void List::display()
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
	Node *previous=NULL,*current;
	Node *temp;
	temp=this->firstNode;
	while(temp!=NULL)
	{
		current=temp;
		temp=temp->next;
		current->next=previous;
		previous=current;
	}
	this->firstNode=previous;
}
int main()
{
	List *first=new List();
	first->createList();
	cout<<"The first order:"<<endl;
	first->display();
	first->reserve();
	cout<<endl;
	cout<<"The second order:"<<endl;
	first->display();
	return 0;
}





















