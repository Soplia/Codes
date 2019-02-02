//快速排序
#include <iostream>
#include <iomanip>
using namespace std;
int getPivot(int *a,int b,int c);
void QuickSort(int *a,int b,int c)
{
	if(b<c)
	{
		int pivot=getPivot(a,b,c);
		QuickSort(a,b,pivot-1);
		QuickSort(a,pivot+1,c); 
	}
} 
//将元素分成左右两边进行分别排序. 
int getPivot(int *a,int b,int c)
{
	int p=b;
	int temp;
	int pivot=a[b];
	for(int i=b+1;i<=c;i++)
	{
		if(a[i]<=pivot)
		{
			temp=a[++p];
			a[p]=a[i];
			a[i]=temp;
		}
	}
	temp=a[p];
	a[p]=a[b];
	a[b]=temp;
	return p;
}
int main()
{
	int array[]={3,2,45,2,7,32,7};
	QuickSort(array,0,6);
	for(int i=0;i<7;i++)
		cout<<setw(4)<<array[i];
	return 0;
}













