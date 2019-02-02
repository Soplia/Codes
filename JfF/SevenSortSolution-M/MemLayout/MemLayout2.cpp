#include <stdio.h>
#include <stdlib.h>

void fun(int i)
{
	int j = i;
	static int s_i = 1, s_j;
	printf("子函数中参数数据地址:%p = %d\n", &i, i);
	printf("子函数中栈数据地址（已初始化）:%p = %d\n", &j, j);
	printf("子函数中静态数据地址（已初始化）:%p = %d\n", &s_i, s_i);
	printf("子函数中静态数据地址（未初始化）:%p = %d\n", &s_j, s_j);
}

int main()
{
	int i = 4;
	static int s_i = 1, s_j;
	printf("主函数中栈数据地址（已初始化）:%p = %d\n", &i, i);

	printf("主函数中静态数据地址（初始化）:%p = %d\n", &s_i, s_i);
	printf("主函数中静态数据地址（未初始化）:%p = %d\n", &s_j, s_j);
	fun(i);
	system("pause");
	return 0;
}