#include <iostream>
#include <iomanip>
using namespace std;
void BulletSort(int *array,int size)
{
	bool notFinish=false;
	int temp;
	int j=0;
	do
	{
		for(int i=0;i<size-1-j;i++)
			if(array[i]>array[i+1])
			{
				temp=array[i];
				array[i]=array[i+1];
				array[i+1]=temp;
				notFinish=true;
			}
		j++;
	}while(notFinish);
} 
//void BulletSort(int *array,int size)
//{
//	int temp;
//	for(int i=0;i<size-1;i++)
//		for(int j=i+1;j<size;j++)
//			if(array[j]<array[i])
//			{
//				temp=array[i];
//				array[i]=array[j];
//				array[j]=temp;
//			}
//}
int main()
{
	int array[]={4,3,2,1};
	BulletSort(array,4);
	for(int i=0;i<4;i++)
		cout<<setw(4)<<array[i];
	return 0;
}
