#include<iostream>
using namespace std;
//������۰����
//����ֵ��Ŀ��Ԫ�ص�λ�ã�left����ʼλ�ã�right����ֹλ�� 
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
	return -1;//����û���ҵ����Ԫ�� 
}
int main()
{
	int array[]={1,2,3,4,5,6};
	cout<<"The position of 6 is:"<<search(6,array,0,5);
	return 0;
}
