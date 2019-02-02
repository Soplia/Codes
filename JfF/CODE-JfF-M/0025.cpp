#include <iostream>
using namespace std;

int MaxSubArrSum(int *a,int size)
{
	if(size<=0)
		return 0;
	else
	{
		int sum=0,result=0;
		for(int i=0;i<size;i++)
		{
			if(sum>0)
				sum+=a[i];
			else
				sum=a[i];
			result=sum>result?sum:result;
		}
		return result;
	}
	
}

int main()
{
	int a[8] = {-2, -5 , 6 ,-2 , -3 , 1,  5, -6};
	 
	cout<<MaxSubArrSum(a,8)<<endl;
	return 0;
}
