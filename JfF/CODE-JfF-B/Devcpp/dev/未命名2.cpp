#include "stdio.h"
#include "conio.h"
int main()
{
	char ch;
	//printf("%c",75);
	while(1)
	{
		printf("Input a char:\n");
		ch=getchar();
		if(ch==75)
			printf("¡û\n");
		if(ch==77)
			printf("¡ú\n");
		if(ch==72)
			printf("¡ü\n");
		if(ch==80)
			printf("¡ý\n");
		getchar();
	}
	return 0;
}
