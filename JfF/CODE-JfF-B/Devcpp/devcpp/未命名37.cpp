#include <stdio.h>
//0��Ϊ�����������0����'0'��ASCII����48
//ASCIIΪ0����NULL,����ʾ����˼�ǿ��ַ��� 
int main()
{
	char a=0;
	printf("%d,%c\n",a*a+'a',a*a+'a');
	printf("%d,%d\n",0,'0');
	printf("%c\n",'0');
	return 0;
}
