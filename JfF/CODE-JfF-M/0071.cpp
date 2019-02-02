#include <iostream>
#include <cmath>
using namespace std;

int arr[] = {1,0,1,1};

int Func(int a, int n);


int main(void)
{
	cout << "result = " << Func(2, 21) << endl;
	cout << (int)pow(2.0,21.0) % 11 << endl;
	return 0;
}

int Func(int a, int n)
{
	int b = 1;
	for(int i = 3; i >= 0; i--)
	{
		b = b * b % n;
		cout << "b = " << b << ", arr[i] = " << arr[i];
		if (arr[i] == 1)
		{
			b = b * a % n;
			cout << ", b = " << b << endl;
		}
		else
			cout << endl;
			
	}
	return b;
}
