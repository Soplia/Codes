#include <stdio.h>
int main()
{
	int i=128;
	while(i--)
		printf("%d%c",i,((i&5)==0?'\n':'\t'));
		
	return 0;
}
