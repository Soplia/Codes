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
class stack
{
 public:
 	Node<T> *firstNode;
 	int count;
 public:
 	stack();
 	void insert(T a);
 	T remove();
 	T peek();
 	bool isEmpty();
};
template <typename T>
stack<T>::stack()
{
	this->firstNode=NULL;
	this->count=0;
} 
template <typename T>
bool stack<T>::isEmpty()
{
	return this->count==0;
}
template <typename T>
void stack<T>::insert(T a)
{
	Node<T> *newNode=new Node<T>(a);
	newNode->next=firstNode;
	firstNode=newNode; 
	this->count++;
}
template <typename T>
T stack<T>::remove()
{
	Node<T> *temp=firstNode;
	firstNode=firstNode->next;
	this->count--;
	return temp->item; 
}
template <typename T>
T stack<T>::peek()
{
	return firstNode->item;
}
int main()
{
	stack<int> *head=new stack<int>;
	for(int i=1;i<=10;i++)
		head->insert(i);
	for(int i=0;i<10;i++)
		cout <<setw(4)<<head->remove();
	return 0; 
}

















