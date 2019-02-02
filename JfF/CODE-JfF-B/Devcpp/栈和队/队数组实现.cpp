#include <iostream>
#include <iomanip>
using namespace std;
template <typename T> 
class Quee
{
 public:
 	int count;
 	int head;
 	int rear;
 	int size;
 	int increment;
 	T *array;
 public:
 	Quee();
 	void insert(T a);
 	T remove();
 	bool isEmpty();
};
template <typename T>
Quee<T>::Quee()
{
	count=0;
	head=rear=0;
	size=increment=10;
	array=new T[size];
}
template <typename T>
void Quee<T>::insert(T a)
{
	if(count>=size)
	{
		T *tempArray=new T[size+increment];
		if(head<rear)
			for(int i=head;i<rear;i++)
			tempArray[i]=array[i];
		else
		{
			for(int i=0;i<rear;i++)
				tempArray[i]=array[i];
			for(int i=head;i<count;i++)
				tempArray[i+increment]=array[i];
		}
		size+=increment;
		array=tempArray;
	}
	array[rear]=a;
	rear=(rear+1)%size;
	this->count++;
} 
template <typename T>
T Quee<T>::remove()
{
	if(!isEmpty())
	{
		T temp=array[head];
		head=(head+1)%size;
		this->count--;
		return temp; 
	}
}
template <typename T>
bool Quee<T>::isEmpty()
{
	return count==0;
}
int main()
{
	Quee<int> *quee=new Quee<int>;
	for(int i=1;i<=10;i++)
		quee->insert(i);
	for(int i=0;i<10;i++)
		cout<<setw(4)<<quee->remove();
	return 0;
}























