/* 
#ifdef 标识符

#else

#endif


#ifndef 标识符

#else

#endif


#if (常量表达式)

#elif 常量表达式

#else


#endif 
*/


#include <stdio.h>

int main()
{
	#if(1==1)
		printf("Hello");
	#else 
		printf("World");
	#endif
	return 0;
}

















