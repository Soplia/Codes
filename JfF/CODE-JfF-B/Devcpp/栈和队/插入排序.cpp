//插入排序
 
#include <iostream>
#include <iomanip>
using namespace std;

void insert(int *a,int size)
{
	int i,j;
	int temp;
	for(int i=1;i<size;i++)
	{
		j=i;
		temp=a[i];//首先删除元素 ,即将要插入的元素. 
		bool notFinish=a[j-1]>a[j];
		while(notFinish)
		{
			a[j]=a[j-1];//元素后移 
			j--;
			if(j>0)
				notFinish=a[j-1]>a[j];
			else
				notFinish=false;
		}
		a[j]=temp;//将元素进行插入 
	}
}
int main()
{
	int array[]={3,2,45,2,7,32,7};
	insert(array,7);
	for(int i=0;i<7;i++)
		cout<<setw(4)<<array[i];
	return 0;
}
