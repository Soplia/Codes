#include <iostream>
#include <iomanip>
#include "队链表实现.cpp"
using namespace std;
class Heap
{
 public:
 	int count;
 	int capacity;
 	int increment;
 	int *array;
 public:
 	Heap();
 	void print();
 	void insert(int a);
 	int remove();	
};
Heap::Heap()
{
	count=0;
	capacity=increment=10;
	array=new int [capacity];
}
void Heap::print()
{
	for(int i=1;i<=count;i++)
		cout<<setw(4)<<array[i];
	cout<<endl;
}
void Heap::insert(int a)
{
	if(count==capacity-1)
	{
		this->capacity+=increment;
		int *tempArray=new int[capacity];
		for(int i=1;i<=count;i++)
			tempArray[i]=array[i];
		array=tempArray;
	}
	count++;
	int childPos=count;
	int parentPos=childPos/2;
	while(parentPos!=0)
	{
		if(array[parentPos]>=a)
		{
			array[childPos]=a;
			return;
		}
		else
		{
			array[childPos]=array[parentPos];
			childPos=parentPos;
			parentPos=childPos/2;
		}
	}
	array[childPos]=a;
}
int Heap::remove()
{
	if(count==0)
		return -1;
	else
	{
		int currentPos=1,childPos=currentPos*2;
		int returnItem=array[currentPos],replaceItem=array[count--];
		while(childPos<=count)
		{
			if(childPos<count)
				if(array[childPos]<array[childPos+1])
					childPos++;
			if(array[childPos]<=replaceItem)
			{
				array[currentPos]=replaceItem;
				return returnItem;
			}
			else
			{
				array[currentPos]=array[childPos];
				currentPos=childPos;
				childPos=currentPos*2;
			}
		}
		array[currentPos]=replaceItem;
		return returnItem;
	}
}
int main()
{
	Heap *head=new Heap();
	for(int i=1;i<11;i++)
		head->insert(i);
	head->print();
	for(int i=1;i<11;i++)
		cout<<setw(4)<<head->remove();
	return 0;
}
























