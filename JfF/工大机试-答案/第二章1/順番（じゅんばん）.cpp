/*
Subject:èáî‘ÅiÇ∂Ç„ÇÒÇŒÇÒÅj 
ID:2.1
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 19:32
Result:Accepted
EndTime:05/02/17 19:53
*/
#include <stdio.h>
#define N 200

int array[N];

//int partition(int low,int high)
//{
//	int pivot=array[low];
//	
//	while(low<high)
//	{	
//		while(low<high&&array[high]>pivot)
//			high--;
//		array[low]=array[high];
//		
//		while(low<high&&array[low]<pivot)
//			low++;
//		array[high]=array[low];
//	}
//	
//	array[low]=pivot;
//	return low;
//}
//
//void quickSort(int low,int high)
//{
//	if(low<high)
//	{
//		int pivot=partition(low,high);
//		quickSort(low,pivot-1);
//		quickSort(pivot+1,high);
//	}
//}

void bSort(int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(array[j]>array[j+1])
			{
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);
			
		//quickSort(0,n-1);
		bSort(n);
		
		for(int i=0;i<n;i++)
			printf("%d ",array[i]);
		printf("\n");
	}
	return 0;
}
/*
InputData:
4
1 4 3 2
OutputData:
1 2 3 4
*/

