#include <iostream>
using namespace std;

int Add(int a, int b);

int main()
{
	cout << Add(1,2) << endl;
	return 0;
}

inline int Add(int a, int b)
{  
	return a + b;
}
