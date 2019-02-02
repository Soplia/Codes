#include<iostream>
using namespace std;
#define size 8
void sort(int *array,int left,int right)
{
	int i=left,j=right;
	int pivot=array[(left+right)/2];
	while(i<=j)
	{
		while(array[i]<pivot)
			i++;
		while(array[j]>pivot)
			j--;
		if(i<=j)
		{
			int temp;
			cout<<"pivot is:"<<pivot<<" left is:"<<array[i]<<" right is:"<<array[j]<<endl;
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i++;
			j--;
			for(int i=0;i<size;i++)
				cout<<array[i]<<"  ";
			cout<<endl<<endl;
		}			
	}
	if(i<right)
		sort(array,i,right);
	if(j>left)
		sort(array,left,j);
} 
int main()
{
	int array[]={4,43,32,6,645,6,54,3};
	for(int i=0;i<size;i++)
		cout<<array[i]<<"  ";
	cout<<endl<<endl;
	sort(array,0,size-1);
	return 0;
}
