#include <iostream>
using namespace std;
int main()
{
	int a=1;
	int b=1;
	for(int i=1;i<10;i++)
	{
		cout<<a<<" "<<b<<" ";
		a=a+b;
		b=a+b;
		if(i%5==0)
			cout<<endl;
	}
	return 0;
}
