#include "stdio.h"
#include "conio.h"
int main()
{
	char ch=0;
	while(1)
	{
		ch=getch();
		if(ch==75)
			printf("��\n");
		if(ch==77)
			printf("��\n");
		if(ch==72)
			printf("��\n");
		if(ch==80)
			printf("��\n");
	}
	return 0;
}

