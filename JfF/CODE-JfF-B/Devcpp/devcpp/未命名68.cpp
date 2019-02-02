//从键盘输入10个学生的信息（学生信息包括姓名、学号和
//成绩），将信息保存在二进制文件“student.dat”中,  然后再从文件中
//读取序号为奇数的学生信息，并这些信息输出到显示器上。
#include <stdio.h>
#include <stdlib.h>
//这个程序还有问题 
int main()
{
	FILE *f;
	int size=20;
	if((f=fopen("student.dat","w+"))==NULL)
	{
		printf("Open the file fail\n");
		exit(0);
	}
	int *a=(int *)malloc(sizeof(int)*size);
	for(int i=0;i<20;i++)
		a[i]=i+1;
		
	fwrite(a,sizeof(int),size,f);
	rewind(f);
	int temp;
	printf("*%d*\n",ftell(f));
	for(int i=1;i<=size/2;i++)
	{
		fread(&temp,sizeof(int),1,f);
		printf("%-3d",temp);
		printf("*%d*\n",ftell(f)); 
		fseek(f,sizeof(int),SEEK_CUR);
	}
	fclose(f);
	return 0;
}
