#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class Node
{
 public:
 	T item;
 	Node *next;
 public:
 	void set(T a);
 	Node();
 	Node(T a);
};
template <class T>
void Node<T>::set(T a)
{
	this->item=a;
	this->next=NULL;
}
template <class T>
Node<T>::Node()
{
	this->set(NULL);
}
template <class T>
Node<T>::Node(T a)
{
	this->set(a);
}

template <class T>
class GenList
{
 public:
 	int count;
 	Node<T> *firstNode;
 public:
 	GenList();
 	GenList(Node<T> *a);
 	int getLength();
 	bool isEmpty();
 	void insert(T a);
 	void print();
};
template <class T>
GenList<T>::GenList()
{
	this->count=0;
	this->firstNode=NULL;
}
template <class T>
GenList<T>::GenList(Node<T> *a)
{
	this->count=0;
	this->firstNode=a;
}
template <class T>
int GenList<T>::getLength()
{
	return this->count;
}
template <class T>
bool GenList<T>::isEmpty()
{
	return this->count==0;
}
template <class T>
void GenList<T>::insert(T a)
{
	Node<T> *temp=new Node<T>(a);
	temp->next=this->firstNode;
	this->firstNode=temp;
}
template <class T>
void GenList<T>::print()
{
	Node<T> *temp=this->firstNode;
	cout<<"(";
	while(temp!=NULL)
	{
			cout<<temp->item;
		if((temp=temp->next)!=NULL)
			cout<<",";
	}
	cout<<")";
}
int main()
{
	GenList<string> *a=new GenList<string>();
	a->insert("a");
	a->insert("b");
	GenList<string> *b=new GenList<string>();
	b->insert("c");
	b->insert("d");
	b->print();
	return 0;
} 




















