#include <iostream>
using namespace std;

void Output(int a);
//ȱʡ����ֵ�������º������� 
void Output(int a,float b=1.1);

int main()
{
	Output(1);
	Output(1,1.4);
	return 0;
}

void Output(int a)
{
	cout<<"Output_Int "<<a<<endl;
}
void Output(int a,float b)
{
	cout<<"Output_Float "<<a<<" , "<<b<<endl;
}
