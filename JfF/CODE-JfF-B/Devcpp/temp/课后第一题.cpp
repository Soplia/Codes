#include <iostream>//k 
#include <fstream>
using namespace std;
void split(int *array,int digit)
{
	bool flag=true;
	do
	{
		if(digit==0)
			flag=false;
		else
		{
			array[digit%10]++;				
			digit/=10;
		}
	}while(flag);
}
int main()
{
	int digit;
	int array[10]={0};
	ifstream in("input.txt");
	if(in.fail())
	{
		cerr<<"Open the input file fail!"<<endl;
		return 1;
	}
	in>>digit;
	in.close();
	if(digit<1)
		cout<<"The input digit is wrong!"<<endl;
	else
	{
		for(int i=1;i<=digit;i++)
			split(array,i);
		ofstream out("output.txt");
		if(out.fail())
		{
			cerr<<"Open the file fail!"<<endl;
			return 1;
		}
		for(int i=0;i<10;i++)
			out<<array[i]<<endl;
		out.close();
	}
	cout<<"Finished!"<<endl;
	return 0;
}
