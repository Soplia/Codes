#include <iostream>
#include <iomanip>
using namespace std;
template <typename Object>
int getPivot(Object *a,int b,int c)
{
	Object pivot=a[b];
	Object temp;
	int p=b;
	for(int i=b+1;i<=c;i++)
		if(a[i]<=pivot)
		{
			temp=a[++p];
			a[p]=a[i];
			a[i]=temp;
		}
	temp=a[b];
	a[b]=a[p];
	a[p]=temp;
	return p;
}
template <typename Object>
void QuickSort(Object *a,int b,int c)
{
	if(b<c)
	{
		int p=getPivot(a,b,c);
		QuickSort(a,b,p-1);
		QuickSort(a,p+1,c);
	}
}
int main()
{
	string str[]={"fd","fde","3te","ut","jhy","y6","jh"};
	QuickSort(str,0,6);
	for(int i=0;i<7;i++)
		cout<<str[i]<<" ";
//	int array[]={3,2,45,2,7,32,7};
//	QuickSort(array,0,6);
//	for(int i=0;i<7;i++)
//		cout<<setw(4)<<array[i];
	return 0; 
}
























