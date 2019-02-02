#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	int cnt=0;
	
	char temp[]="i miss you";
	
	puts(temp);
	
	for(int i=0;temp[i]!='0';i++)
	{
		cnt++;
		printf("%c",temp[i]);
	}
	
	printf("\n%d\n",cnt);
	return 0;
}
