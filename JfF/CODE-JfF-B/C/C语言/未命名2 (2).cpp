#include <stdio.h>
#include "1.h"
#define LETTER 0

int main()
{
	
	char str[]="Hello World";
	int posOfStr=0;
	while(str[posOfStr]!='\0')
	{
		//���������ȷ�Ǻ�
		//���������ܺÿ� 
		#if LETTER
		if(str[posOfStr]>'a'&&str[posOfStr]<'z')
			str[posOfStr]-=32;
		#else
		if(str[posOfStr]>'A'&&str[posOfStr]<'Z')
			str[posOfStr]+=32;
		#endif
		
		posOfStr++;
	}
	PD(S,str);
	PD(NL D,0377);
	return 0;
	
}

