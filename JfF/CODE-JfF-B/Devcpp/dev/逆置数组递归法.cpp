#include <iostream>
#include <iomanip>
using namespace std; 
void reserve(int *arr,int left,int right);
int main()
{
	int array[]={1,2,3,4,5,6,7};
	reserve(array,0,6);
	for(int i=0;i<7;i++)
		cout<<setw(4)<<array[i];
	return 0;
}
void reserve(int *arr,int left,int right)
{
	int temp;
	if(left<right)
	{
		temp=arr[left];
		arr[left]=arr[right];
		arr[right]=temp;
		reserve(arr,left+1,right-1);
	}
}
