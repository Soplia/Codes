#include <iostream>
using namespace std;

int main()
{
	float *p=NULL;
	while(true)
	{
		p=new float[10000000];
		cout<<"eat memory..."<<endl;
		if(NULL==p)
		{
			cout<<"memory is not enough..."<<endl;
			exit(1);
		}
			
	}
	return 0;
}
