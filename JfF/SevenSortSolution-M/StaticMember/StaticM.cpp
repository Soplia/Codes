#include <iostream>
using namespace std;

class StaticTest
{
public:
	StaticTest()
	{
		countNum++;
	}
	~StaticTest()
	{
		countNum--;
	}
	static int countNum;
};

int StaticTest :: countNum = 6;
/*
int main()
{
	StaticTest s ;
	cout << s.countNum << endl;
	system("pause");
	return 0;
}
*/