#include <iostream>
#include <iomanip>
using namespace std;
void insertSort(int *a,int size)
{
	int i,j;
	int temp;
	for(i=1;i<size;i++)
	{
		j=i;
		temp=a[i];
		bool notFinish=a[j-1]>a[j];
		while(notFinish)
		{
			a[j]=a[j-1];
			j--;
			if(j>0)
				notFinish=a[j-1]>temp;//这个地方是和temp相比较的 
			else
				notFinish=false;
		}
		a[j]=temp;
	}
}
int main()
{
	int array[]={5,4,3,2,1};
	insertSort(array,5);
	for(int i=0;i<5;i++)
		cout<<setw(4)<<array[i];
	return 0;
}
