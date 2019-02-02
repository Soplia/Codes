#include <stdio.h>

int CheckMem(void)
{
	union
	{
		int i;
		char ch;
	}*p, u;
	p = &u;
	p->i = 1;
	return p->ch == 1;
}

int main()
{
	if (CheckMem())
		printf("BigEndian\n"); 
	else
		printf("LittleEndian\n");
	return 0;
}
