#include <stdio.h>
#include <stdlib.h>

void Judge()
{
	const int size = 100;
	for (int i = 0; i < size; i++)
		if (i & 1)
			printf("%d\n", i);
}

void Swap(int &a, int &b)
{
	if (a != b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
}

void SwapOper(int &a)
{
	a = ~a + 1;
}

void Abs1(int &a)
{
	int oper = a >> 31;
	a = oper == 0 ? a : (~a + 1);
}

//任何数与0异或还是其本身
//任何数与-1异或则取反
void Abs2(int &a)
{
	int oper = a >> 31;
	a = (a ^ oper) - oper;
 }
/*
int main()
{
	int a = 6, b = 6;
	printf("%d\n", (a >> 1));
	b <<= 1;
	printf("%d\n", b);
	//Judge();
	printf("a = %d, b = %d\n", a, b);
	Swap(a, b);
	printf("a = %d, b = %d\n",a, b);
	

	int temp = -12;
	SwapOper(temp);
	printf("temp = %d\n", temp);
	Abs1(temp);
	printf("temp = %d\n", temp);
	SwapOper(temp);
	printf("temp = %d\n", temp);
	Abs2(temp);
	printf("temp = %d\n", temp);

	system("pause");
	return 0;
}
*/