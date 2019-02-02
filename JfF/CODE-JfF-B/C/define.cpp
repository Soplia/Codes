//获得文件的名字
#include <iostream>
#include <cstring>
using namespace std;

#define SQR(X) printf("The square of X is:%d\n",(X)*(X));
#define SQR1(X) printf("The square of "#X" is:%d\n",(X)*(X));

int main()
{
	SQR(8);
	SQR1(8);
	return 0;
}
