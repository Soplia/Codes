/*
	Name: 用优先级队列实现排序 
	Complier:Devcpp 
	Author: 青盲 
	Date: 17/02/15 13:09
	Description: 利用递归来实现的。 
*/

#include<iostream>
#include<iomanip>
using namespace std;
//定义节点类 
class Node
{
 public:
 	Node();
 	Node(int a);
 	void set(int a);
 	void show();
	//比较两个数的大小，用于以后的插入。 
 	int compare(int a);
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
int Node::compare(int a)
{
	return (this->data==a)?0:(this->data>a)?1:-1;
}
//定义链表类型 
class List
{
 public:
 	void show();
	//插入方法，这是一个辅助方法，利用递归进行定义的。 
 	Node *insert(int a,Node *b);
 	void insert(int *arr,int count);
	//按照优先级队列的定义进行删除操作。 
 	int remove();
 	Node *firstNode;
 	int length;
};
void List::show()
{
	if(this->firstNode==NULL)
		cout<<"The list is empty!"<<endl;
	else
	{
		Node *temp=this->firstNode;
		while(temp!=NULL)
		{
			temp->show();
			temp=temp->next;
		}
	}
}
Node* List::insert(int a,Node *b)
{
	if(b==NULL||b->compare(a)<0)
	{
		Node *temp;
		temp=new Node(a);
		temp->next=b;
		return temp;
	}
	else
	{
		b->next=insert(a,b->next);
		return b;
	}
}
void List::insert(int *arr,int count)
{
	for(int i=0;i<count;i++)
	{
		this->firstNode=insert(arr[i],this->firstNode);
		this->length++;
	}
}
int List::remove()
{
	if(this->firstNode==0)
		cout<<"The list is empty!"<<endl;
	else
	{
		int temp=this->firstNode->data;
		firstNode=firstNode->next;
		return temp;
	}			 
}
int main()
{
	int array[]={5,4,3,2,1};
	List *list=new List();
	list->insert(array,5);
	for(int i=4;i>=0;i--)
		array[i]=list->remove();
	for(int i=0;i<5;i++)
		cout<<setw(4)<<array[i];
	cout<<endl;
	return 0;
}






















