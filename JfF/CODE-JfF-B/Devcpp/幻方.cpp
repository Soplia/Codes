/*
	Name: 幻方 
	Complier:Devcpp 
	Author: jiarui-xie
	Date: 29/01/15 15:46
	Description: 九子斜排，上下对易，左右向更，四维挺出，戴九履一，二四为肩，六八为足； 
*/

#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	int row;
	cout<<"Input the amount of the rows:"<<endl;
	cin>>row;
	int array[row][row];
	int i=0;
	int j=row/2;
	for(int a=1;a<=row*row;a++)
	{
		array[i][j]=a;
		if(a%row==0)
			i=(i+1)%row;
		else
		{
			i=(i-1+row)%row;
			j=(j+1)%row;
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<row;j++)
			cout<<setw(4)<<array[i][j];
		cout<<endl;
	}
	return 0;
}
