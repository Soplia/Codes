#include <iostream>
#include <iomanip>
using namespace std;
int remove(int *array,int count)
{
	int pos=0;
	int max=*array;
	for(int i=0;i<count;i++)
		if(max>*(array+i))
		{
			pos=i;
			max=array[i];
			break;
		}
	array[pos]=array[count-1];
	return max;
}
int main()
{
	int arr[]={5,4,3,2,1}; 
	int array[5];
	for(int i=0;i<5;i++)
		array[i]=remove(arr,5-i);
	for(int i=0;i<5;i++)
		cout<<setw(4)<<array[i];
	cout<<endl;
	return 0;
}
