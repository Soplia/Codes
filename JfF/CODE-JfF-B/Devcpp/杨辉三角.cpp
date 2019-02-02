#include <iostream>
using namespace std;
int main()
{
	int array[10][10];
	for(int i=0;i<10;i++)
	{
		array[i][0]=array[i][i]=1;
		for(int j=1;j<i;j++)
			array[i][j]=array[i-1][j]+array[i-1][j-1];
	}
	for(int i=0;i<10;i++)
	{
		for(int k=1;k<=15-i;k++)
			cout<<" ";
		for(int j=0;j<i+1;j++)
			cout<<"  "<<array[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
