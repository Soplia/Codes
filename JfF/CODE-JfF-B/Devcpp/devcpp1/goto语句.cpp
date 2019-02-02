/*
	Subject:goto语句 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:
	Date_Begin:15/01/17 10:11
	Date_End:
*/
#include <stdio.h>
#include <stdlib.h>
const int len=1000;
int main()
{
	char *a=(char *)malloc(sizeof(char)*len);
	if(a==NULL)
	{
		printf("内存分配失败！\n");
		goto Solve;
	}
	else if(a!=NULL)
		printf("内存a分配成功\n");
		
	char *b=(char *)malloc(sizeof(char)*len);
	if(b==NULL)
	{
		printf("内存分配失败！\n");
		goto Solve;
	}
	else if(b!=NULL)
		printf("内存b分配成功\n");
		
	
	goto Solve;
	 
	Solve://只要内存未成功分配，把所有使用malloc分配的内存空间都释放掉。 
		if(a!=NULL)
		{
			free(a);
			printf("已经释放a\n");
		}
		if(b!=NULL)
		{
			free(b);
			printf("已经释放b\n");
		}
			
			
	return 0;
}
