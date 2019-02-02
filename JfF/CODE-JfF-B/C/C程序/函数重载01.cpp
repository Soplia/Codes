#include <iostream>
using namespace std;

void FunIntChar(int ,char)
{
	cout<<"IntChar"<<endl;
}

void FunIntChar(char,int)
{
	cout<<"CharInt"<<endl;
}

int main()
{
	FunIntChar(1,'2');
	FunIntChar('1',2);
	return 0;
}
