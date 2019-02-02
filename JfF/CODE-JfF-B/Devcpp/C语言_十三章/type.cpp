/*
	Subject:键入文件名，将文件内容显示到屏幕上 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:
	Date_Begin:19/01/17 12:09
	Date_End:19/01/17 12:09
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char name[20];
	gets(name);
	
	FILE *f;
	if((f=fopen(name,"rb+"))==NULL) 
	{
		printf("打开文件失败!\n");
		exit(0);
	}
	
	char ch;
	//第一种读写方法 
//	while((ch=fgetc(f))!=EOF)
//		printf("%c",ch);

	//第二种读写方法 
//	while(!feof(f))
//	{
//		printf("%c",fgetc(f));
//	}
	char n[100];
	//第三种读写方法 
//	while(!feof(f))
//	{
//		printf("%s",fgets(n,100,f));
//	}
	
	printf("\n");
	fclose(f);
	return 0;
}
/*
输入数据
deme.txt
*/




























