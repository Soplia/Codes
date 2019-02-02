#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
class Heap
{
 public:
 	int count;
 	int capacity;
 	int increment;
 	T *array;
 public:
 	Heap();
 	void insert(T a);
 	T remove();
 	void print();
};
template<typename T>
Heap<T>::Heap()
{
	count=0;
	capacity=increment=10;
	array=new T[capacity];
}
template <typename T>
void Heap<T>::print()
{
	for(int i=1;i<=count;i++)
		cout<<setw(4)<<array[i];
	cout<<endl;
}
template<typename T>
void Heap<T>::insert(T a)
{
	if(count==capacity-1)//此处是为了接应后面的count-- 
	{
		capacity+=increment;
		T *tempArray=new T[capacity];
		for(int i=1;i<=count;i++)//注意此处是i<=count，而不是i<count; 
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
template <typename T>
T Heap<T>::remove()
{
	if(count>0)
	{
		int currentPos=1;
		int childPos=currentPos*2;
		int returnItem=array[currentPos];
		int replaceItem=array[count--];
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
	Heap<int> a;
	for(int i=1;i<11;i++)
		a.insert(i);
	a.print();
	for(int i=1;i<11;i++)
		cout<<setw(4)<<a.remove();
	return 0;
}
























