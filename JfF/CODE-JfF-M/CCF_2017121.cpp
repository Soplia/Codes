#include <iostream>
#include <algorithm>

using namespace std;

const int n=1000;
int array[n];
int res[n];

bool complare(int a,int b)
{
	return a>b;
}

int main()
{
	int size;
	while(1)
	{
		cin>>size;
	
		for(int i=0;i<size;i++)
			cin>>array[i];
			
		sort(array,array+size,complare);
	
		for(int i=0;i<size-1;i++)
			res[i]=array[i]-array[i+1];
		int temp=res[0];
		for(int i=1;i<size-1;i++)
			if(res[i]<temp)
				temp=res[i];
		cout<<temp;
	}
	
	return 0;
	
}
