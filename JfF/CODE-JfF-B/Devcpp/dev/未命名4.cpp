#include "stdio.h"
#include "conio.h"
int main()
{
	char ch=0;
	while(1)
	{
		ch=getch();
		if(ch==75)
			printf("¡û\n");
		if(ch==77)
			printf("¡ú\n");
		if(ch==72)
			printf("¡ü\n");
		if(ch==80)
			printf("¡ý\n");
	}
	return 0;
}

