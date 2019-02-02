#include <stdio.h>
//0作为整形输出就是0，而'0'的ASCII码是48
//ASCII为0的是NULL,它表示的意思是空字符。 
int main()
{
	char a=0;
	printf("%d,%c\n",a*a+'a',a*a+'a');
	printf("%d,%d\n",0,'0');
	printf("%c\n",'0');
	return 0;
}
