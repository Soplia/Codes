#include <iostream>
#include <cstdlib>
using namespace std;

void Func()
{
	cout<<"HelloWorld"<<endl;
}

int main()
{
	int *p=(int *)malloc(sizeof(int)*2);
	//int *p=NULL;
	free(p);
	Func();
	cout<<"First Free..."<<endl;
	free(p);
	cout<<"Second Free..."<<endl;
	free(p);
	cout<<"Third Free..."<<endl;
	free(p);
	
	return 0;
}
