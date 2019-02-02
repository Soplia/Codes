#include<iostream>
using namespace std;
//这个是折半查找
//返回值是目标元素的位置，left是起始位置，right是终止位置 
int search(int aim,int *array,int left,int right)
{
	int mid=(left+right)/2;
	if(array[mid]==aim)
		return mid;
	else
	{
		if(aim>array[mid])
			search(aim,array,mid+1,right);
		if(aim<array[mid])
			search(aim,array,left,mid-1);
	}
	return -1;//代表没有找到这个元素 
}
int main()
{
	int array[]={1,2,3,4,5,6};
	cout<<"The position of 6 is:"<<search(6,array,0,5);
	return 0;
}
