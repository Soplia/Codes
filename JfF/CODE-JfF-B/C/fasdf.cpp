#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int size=10;

typedef struct stu
{
	char* name;
	int score;
	void init()
	{
		name=(char*)malloc(sizeof(char)*size);
	}
	void end()
	{
		free(name);
		name=NULL; 
		printf("free the memory of name!\n");
	}
}STU;

int main()
{
	STU myStu;
	myStu.init();
	if(myStu.name!=null)
		strcpy(myStu.name,"Jimm");
	puts(myStu.name);
	//������ʹ�õ�ʱ��û�н����ͷţ�Ҳû�г��� 
	myStu.end();
	return 0;
}
