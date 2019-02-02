#include <iostream>
#include <iomanip>
using namespace std;
template <typename Object>
void insertSort(Object *a,int size)
{
	int i,j;
	Object temp;
	for(i=1;i<size;i++)
	{
		j=i;
		temp=a[i];
		bool notFinish=a[j-1]>a[j];
		while(notFinish)
		{
			a[j]=a[--j];
			if(j>0)
				notFinish=a[j-1]>temp;
			else
				notFinish=false;
		}
		a[j]=temp;
	}
}
int main()
{
	char c[]={'4','a','g','y','b','7'};
	insertSort(c,6);
	for(int i=0;i<6;i++)
		cout<<setw(4)<<(char)c[i];
	return 0;
}
