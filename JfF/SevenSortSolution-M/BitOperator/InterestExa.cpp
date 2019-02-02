#include <stdio.h>

int soInt = sizeof(unsigned short) * 8;

template <typename T>
void DisBit(T a)
{
	for (int i = 1; i <= soInt; i++)
	{
		if (a & (1 << (soInt - i)))
			putchar('1');
		else
			putchar('0');
		if (i == 8)
			putchar(' ');
	}
		
		
	puts("");
}

template <typename T>
void ReverseBit(T &a)
{
	a = ((a & 0xAAAA) >> 1) | ((a & 0x5555) << 1);
	a = ((a & 0xCCCC) >> 2) | ((a & 0x3333) << 2);
	a = ((a & 0xF0F0) >> 4) | ((a & 0x0F0F) << 4);
	a = ((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8);
}

template <typename T>
void CountTheNum(T &a)
{
	a = ((a & 0xaaaa) >> 1) + (a & 0x5555);
	a = ((a & 0xcccc) >> 2) + (a & 0x3333);
	a = ((a & 0xf0f0) >> 4) + (a & 0x0f0f);
	a = ((a & 0xff00) >> 8) + (a & 0x00ff);
}

int BitAdd(int a, int b)
{
	int carry = a & b;
	int sum = a ^ b;
	if (0 != carry)
		return BitAdd(sum, carry << 1);
	return sum;
}

int Mult3(int a)
{
	return BitAdd(a << 1, a);
}

int main()
{
	unsigned short a = 34520;
	DisBit(a);
	ReverseBit(a);
	
	DisBit(a);

	CountTheNum(a);
	DisBit(a);
	//a = a << soInt / 2 | a >> soInt / 2;
	//DisBit(a);

	printf("%d\n", BitAdd(92,45));
	printf("%d\n", Mult3(92));

	getchar();
	return 0;
}