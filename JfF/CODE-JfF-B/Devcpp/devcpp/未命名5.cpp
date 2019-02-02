//输入一个字母，要求以大写形式输出
#include <stdio.h>
int main()
{
	char a;
	printf("输入一个字母：\n");
	scanf("%c",&a);
	printf("%c",a-32);
	return 0;
}
