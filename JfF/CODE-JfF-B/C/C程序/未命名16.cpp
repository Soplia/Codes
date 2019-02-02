#include <iostream>
using namespace std;

void Output(int a)
{
	cout<<"Int "<<a<<endl;
}

void Output(float a)
{
	cout<<"Float "<<a<<endl;
}

int main()
{
	Output(0.5);
	Output((int)0.5);
	Output((float)0.5);
	return 0;
}
