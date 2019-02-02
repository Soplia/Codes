//从键盘输入10个整数, 将它们保存到文件“int_file.dat”中；
// 然后从文件中读取这10个整数输出到显示器上

//使用fwrite向文件中存放的时候是按照“块”进行存放的，比如如果是int就会按照4个字节一次进行存放
//但是fgetc每次只取一个字节，所以如果使用这个函数进行存取，那么，必定会出现乱码，但是如果是字符呢？/hx 
//通过实验发现，这样是行不通的，因为在制作文件指针的时候已经规定了是二进制的读写方式；并且就算是在指定
//读写方式的是否故意写成是字符型的读写方式，但是只要是使用fread、fwrite 函数，它就会自动使用二进制读写方式。
//所以两种读写方式不能够进行混用。 

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	if((f=fopen("int_file.dat","w"))==NULL)
	{
		printf("Open the file fail!\n");
		exit(0);
	}
	int size=10;
	char *a=(char *)malloc(sizeof(char)*10);
	for(int i=0;i<10;i++)
		scanf("%c",(a+i));
	fwrite(a,sizeof(char),size,f);
	fclose(f);
	printf("Save Successfully!\n");
//	if((f=fopen("int_file.dat","rb"))==NULL)
//	{
//		printf("Open the file fail\n");
//		exit(0);
//	}
//	int *b=(int *)malloc(sizeof(int )*10);
//	fread(b,sizeof(int),size,f);
//	fclose(f);
//	for(int i=0;i<size;i++)
//			printf("%-3d",*(b+i));
	if((f=fopen("int_file.dat","r"))==NULL)
	{
		printf("Open the file fail!\n");
		exit(0);
	}
	char aa;
	while((aa=fgetc(f))!=EOF)
		printf("%c",aa);
	
	return 0;
}
                
