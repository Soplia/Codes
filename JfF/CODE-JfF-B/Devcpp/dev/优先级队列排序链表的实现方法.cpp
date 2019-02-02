/*
	Name: �����ȼ�����ʵ������ 
	Complier:Devcpp 
	Author: ��ä 
	Date: 17/02/15 13:09
	Description: ���õݹ���ʵ�ֵġ� 
*/

#include<iostream>
#include<iomanip>
using namespace std;
//����ڵ��� 
class Node
{
 public:
 	Node();
 	Node(int a);
 	void set(int a);
 	void show();
	//�Ƚ��������Ĵ�С�������Ժ�Ĳ��롣 
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
//������������ 
class List
{
 public:
 	void show();
	//���뷽��������һ���������������õݹ���ж���ġ� 
 	Node *insert(int a,Node *b);
 	void insert(int *arr,int count);
	//�������ȼ����еĶ������ɾ�������� 
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






















