#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
class Node
{
 public:
 	T item;
 	Node *next;
 public:
 	Node();
 	Node(T a);
 	void set(T a);
};
template <typename T>
Node<T>::Node()
{
	this->set(NULL);
} 
template <typename T>
Node<T>::Node(T a)
{
	this->set(a);
}
template <typename T>
void Node<T>::set(T a)
{
	this->item=a;
	this->next=NULL; 
}
template <typename T> 

class Quee
{
 public:
 	Node<T> *headNode;
 	Node<T> *rearNode;
	int count;
 public: 
 	Quee();
 	void insert(T a);
 	T remove();
 	bool isEmpty();
};
template <typename T>
Quee<T>::Quee()
{
	headNode=rearNode=NULL;
	this->count=0;
}
template <typename T>
void Quee<T>::insert(T a)
{
	Node<T> *newNode=new Node<T>(a);
	if(rearNode==NULL)
		headNode=rearNode=newNode;
	else
	{
		rearNode->next=newNode;
		rearNode=newNode;
	}
	this->count++;
}
template <typename T>
bool Quee<T>::isEmpty()
{
	return count==0;
} 
template <typename T>
T Quee<T>::remove()
{
	if(headNode==NULL)
		rearNode=NULL;
	if(!isEmpty())
	{
		Node<T> *temp=headNode;
		headNode=headNode->next;
		return temp->item; 
	}
}





















