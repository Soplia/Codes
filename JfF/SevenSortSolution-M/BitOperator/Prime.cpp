#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#define MAX 101

bool flag[MAX];
int pi = 0;
int prime[MAX / 3 + 1];
const int soInt = sizeof(int) * 8;

void JudgePrime()
{
	for (int i = 2; i < MAX; i++)
		if (!flag[i])
		{
			prime[pi++] = i;
			//记得以前使用乘法，感觉的确不如加法好
			for (int j = i; j < MAX; j += i)
				flag[j] = true;
		}
}

void JudgePrimeBit()
{
	int flag[MAX / soInt + 1] = { 0 };

	for (int i = 2; i < MAX; i++)
	{
		if (!(flag[i / soInt] & (1 << (i % soInt))))
			prime[pi++] = i;
		for (int j = i; j < MAX; j += i)
			flag[j / soInt] |= (1 << (j % soInt));
	}
}

void Dis()
{
	for (int i = 0; i < pi; i++)
	{
		if (0 != i && i % 5 == 0)
			printf("\n");
		printf("%5d", prime[i]);
	}
	printf("\n");
	int j = 0;
	j |= 1 << 10;
	printf("%5d", j);
	printf("\n");

	int k = 1 << 10;
	if (k & (1 << 10))
		printf("%d\n", 3 % 32);
	else 
		printf("World\n");
}	

void Test()
{
	int b[5] = { 0 };

	for (int i = 0; i < 5 * soInt; i += 2)
		b[i / soInt] |= 1 << (i % soInt);

	for (int i = 0; i < 5 * soInt; i ++)
	{
		if (b[i / soInt] & (1 << (i % soInt)))
			putchar('1');
		else
			putchar('0');
	}
	puts("\n");
}
/*
int main()
{
	//memset(flag, false, sizeof(bool) * MAX);
	//JudgePrime();
	JudgePrimeBit();
	Dis();
	//Test();
	system("pause");
	return 0;
}
*/