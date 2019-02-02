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
	//真正的使用的时候，没有进行释放，也没有出错。 
	myStu.end();
	return 0;
}
