#include <stdio.h>
#include <windows.h>
#include <string.h>

int main()
{
	const int total = 10;
	for (int i = 1; i <= total; i++)
	{
		printf("ÒÑÍê³É£º%.2lf%%\r", i * 100.0 / total);
		Sleep(200);
	}
	Sleep(2000);

	printf("123456789123456\r");
	Sleep(4000);
	char str[] = "Hello JiaruiXie";
	for (int i = 0; i < strlen(str); i++)
	{
		putchar(str[i]);
		Sleep(300);
	}
	printf("\n");
	system("pause");
	return 0;
}