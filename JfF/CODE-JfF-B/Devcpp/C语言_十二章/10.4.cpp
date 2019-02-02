#include <stdio.h>
#include <string.h>

typedef struct ca
{
	char name[20];
	int ret;
	void init(char a[])
	{
		strncpy(name,a,20);
		ret=0;
	}
}C;

C myC[3]={"zhang",0,"li",0,"wang",0};

int main()
{
	int rest=0;
	char n[20];
	
	for(int i=0;i<10;i++)
	{
		//fgets(n,sizeof(char )*20,stdin);
		//使用scanf读入字符串时不会有多余的空格
		//但是使用fgets和get时都会有多余的空格 
		scanf("%s",n);
		//使用这个strlwr进行大小写字母转换 
		strlwr(n);
		printf("*%s*\n",n);
		if(strcmp(n,"zhang")==0)
			myC[0].ret++;
		else if(strcmp(n,"li")==0)
			myC[1].ret++;
		else if(strcmp(n,"wang")==0)
			myC[2].ret++;
		else
			rest++;
	}
	
	for(int i=0;i<3;i++)
		printf("%s:%d\n",myC[i].name,myC[i].ret);
	printf("%d\n",rest);
	
	return 0;
}

/*
测试数据
样例输入
li
li
Li
wang
zhang
Wang
Zhang
wang
li 
lii 
样例输出
li:4
zhang:2
wang:3
1
*/


























