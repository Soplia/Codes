#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
class stack
{
 public:
	int count;
	int size;
	int increment;
	T *array;
 public:
 	stack();
	void insert(T a);
	bool isEmpty();
	T remove();
	T peek();	
};
template <typename T>
stack<T>::stack()
{
	this->count=0;
	this->size=10;
	this->increment=10;
	this->array=new T[this->size]; 
}
template <typename T>
void stack<T>::insert(T a)
{
	if(count>=size)
	{
		T tempArray[size+increment];
		for(int i=0;i<count;i++)
			tempArray[i]=array[i];
		size+=increment;
		array=tempArray;
	}
	array[count++]=a;
	
}
template <typename T>
bool stack<T>::isEmpty()
{
	return count==0;
}
template <typename T>
T stack<T>::remove()
{
	if(!isEmpty())
		return array[--count];	//注意这个地方是先减减，在使用count的值. 
}
template <typename T>
T stack<T>::peek()
{
	int t;
	if(!isEmpty())
	{
		t=array[count-1];
		return t;
	}		
}
int main()
{
	stack<int> *myStack=new stack<int>();
	for(int i=1;i<=7;i++)
		myStack->insert(i);
	for(int i=0;i<10;i++)
		cout<<setw(5)<<myStack->remove();
	cout<<endl;
	return 0;
}
























