#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
  
int main()
{
	  
	    __asm__ (assembler template   
               : [output operand list]                  /* optional */  
               : [input operand list]                   /* optional */  
               : [clobbered register list]              /* optional */  
               );
	int a[10];
	memset(a,0,sizeof(a));
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}
