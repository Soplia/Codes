//输入一行字符, 统计其中有多少个单词
#include<stdio.h>
#include<string.h>

bool is(char);

int main()
{
	char a[100];
	gets(a);
	int num=0;
	int word=0;
	for(int i=0;i<strlen(a);i++)
		if(!is(a[i]))
			word=0;
		else
			if(word==0)
			{
				word=1;
				num++;
			}
	printf("The num is:%d\n",num);
	return 0;
}

bool is(char a)
{
	//return (a==' ')?true:false;
	return ('a'<=a&&a<='z'||'A'<=a&&a<='Z')?true:false;
}
