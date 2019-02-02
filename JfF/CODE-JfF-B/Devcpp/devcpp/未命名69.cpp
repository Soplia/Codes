//统计文本文件中字符的个数
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size=30;
	FILE *f;
	if((f=fopen("count.dat","wb+"))==NULL)
	{
		printf("Open count.txt fail!\n");
		exit(0);
	}
	char *a=(char *)malloc(sizeof(char)*size);
	printf("Input a string:\n");
	gets(a);
	//将数据写入到文件中 
	fputs(a,f);
	//将问价指针重新指定到文件的开头 
	rewind(f);
	int count=0;
	char c;
	while(!feof(f))
	{
		c=fgetc(f);
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
			count++;
		printf("%c",c);
	}
	printf("\nThe number of the char in the file is:%d\n",count);
	return 0;
}
