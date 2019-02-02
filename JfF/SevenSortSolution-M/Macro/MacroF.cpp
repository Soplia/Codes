#include <stdio.h>
#include <stdlib.h>

//调用的时候现在这一步就对其进行展开，
//然后再将变量传送到另外一个宏中进行打印输出
#define MakeString(x) _MakeString(x)
#define _MakeString(x) #x
#define MakeString1(x) #x
#define MakeChar(x) #@x

#define Paster(x) printf("token"#x" = %d\n", token##x);

#define __WFILE__  WFILE(__FILE__)
#define WFILE(x)  _WFILE(x)
#define _WFILE(x)  L##x


int main()
{
	char a = MakeChar(x);
	char b[] = MakeString1(__FILE__\n);
	char c[] = MakeString(__FILE__\n);
	wchar_t *d = __WFILE__;

	char *e = "Hello World\n";

	int token9 = 100;
	int x = 9;
	Paster(9);
	printf("%c\n", a);
	printf("%s", b);
	printf("%s\n", d);
	wprintf(WFILE("%s\n"), d);
	system("pause");
	return 0;
}