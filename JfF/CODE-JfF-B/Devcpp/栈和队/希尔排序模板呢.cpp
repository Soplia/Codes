#include <iostream>
#include <iomanip>
using namespace std;
template <typename Object>
void deltaSort(Object *array,int size,int start,int delta)
{
	int i,j;
	Object temp;
	for(i=start+delta;i<size;i+=delta)
	{
		j=i;
		temp=array[j];
		//用temp这个元素与前面的元素array[j-delta]进行比较. 
		bool notFinish=array[j-delta]>temp;
		while(notFinish)
		{
			array[j]=array[j-=delta];
			if(j>start)
				notFinish=array[j]>temp;
			else
				notFinish=false;
		}
		array[j]=temp;
	}
}
template <typename Object>
void ShellSort(Object *array,int size)
{
	int delta=size;
	do
	{
		delta/=3;
		for(int i=0;i<delta;i++)
			deltaSort(array,size,i,delta);
	}while(delta>=1);
}
int main()
{
	int array[]={9,8,7,6,5,4,3,2,1};
	ShellSort(array,9);
	for(int i=0;i<9;i++)
		cout<<setw(4)<<array[i];
	return 0;
}

















