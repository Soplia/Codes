#include "stdio.h"
#include "conio.h"
#include <iostream>
using namespace std;
int main()
{
	int ch=0;
		ch=getch();
		if(ch==224)
			ch=getch();
		cout<<ch<<endl; 
		if(ch==75)
			printf("��\n");
		if(ch==77)
			printf("��\n");
		if(ch==72)
			printf("��\n");
		if(ch==80)
			printf("��\n");
	return 0;
}

