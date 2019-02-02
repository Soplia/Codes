#include <iostream>
using namespace std;

void Print()
{
	cout << "G_Print" << endl;
}

class Test
{
 public:
 	void Print();	
};
void Test::Print()
{
	::Print();
	cout << "M_Print" << endl;
}

int main()
{
	Test t;
	t.Print();
	return 0;
}
