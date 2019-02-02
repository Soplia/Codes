#include <iostream>
#include <iomanip>
using namespace std;
void deltaSort(int *a,int ,int t,int); 
void ShellSort(int *a,int size)
{
	 int delta=size;
	 do
	 {
	 	delta=delta/3;
	 	//cout<<"delta is:"<<delta<<endl;
	 	for(int i=0;i<delta;i++)//将在这个区间内的元素进行排序
		 {
		 	deltaSort(a,i,delta,size);
		 	//for(int i=0;i<9;i++)
				//cout<<setw(8)<<a[i];
			//cout<<endl;
		 } 
		 	
	 }while(delta>=1);
} 
void deltaSort(int *a,int start,int delta,int size)
{
	int i,j;
	int temp;
	for(int i=start+delta;i<size;i+=delta)//每一次的i的增量是多少啊。 
	{
		j=i;
		temp=a[i];
		bool notFinish=a[j-delta]>temp;
		while(notFinish)
		{
			a[j]=a[j-delta];
			j-=delta;
			if(j>start)//注意此处的条件. 
				notFinish=a[j-delta]>temp;
			else
				notFinish=false;
		}
		a[j]=temp;		
	}
} 
int main()
{
	int array[]={9,8,7,6,5,4,3,2,1};
	ShellSort(array,9);
	for(int i=0;i<9;i++)
		cout<<setw(4)<<array[i];
	return 0;
}

























