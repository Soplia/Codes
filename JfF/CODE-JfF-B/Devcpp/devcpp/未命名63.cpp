//从键盘输入10个整数, 将它们保存到文件“int_file.dat”中；
// 然后从文件中读取这10个整数输出到显示器上。
//有待于进一步的完善
 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	char *a=(char *)malloc(sizeof(char)*10);
	if((f=fopen("int_file.dat","wb"))==NULL)
	{
		printf("Open int_file.dat fail!\n");
		exit(0);
	}
	else
	{
		//int *a=(int *)malloc(sizeof(int)*10);
		printf("Input ten num:\n");
		gets(a);
		fputs(a,f);
		fclose(f);
	}
	if((f=fopen("int_file.dat","rb"))==NULL)
	{
		printf("Open int_file.dat fail!\n");
		exit(0);
	}
	else
	{
		fgets(a,100,f);
		puts(a);
		fclose(f);
	} 
	return 0;
}


