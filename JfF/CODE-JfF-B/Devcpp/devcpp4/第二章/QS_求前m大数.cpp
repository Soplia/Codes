/*
	Subject:QS_求前m大数 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:2-3-2
	Date_Begin:05/01/17 18:17
	Date_End:
*/

#include <stdio.h>

int partition(int *a,int low,int high)
{
	int pivot=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>pivot)
			high--;
		a[low]=a[high];
		while(low<high&&a[low]<pivot)
			low++;
		a[high]=a[low];
	}
	a[low]=pivot;
	return low;
}

int main()
{
	
}














