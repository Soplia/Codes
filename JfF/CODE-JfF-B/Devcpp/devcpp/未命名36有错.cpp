//从键盘输入一串字符，输入‘#’时结束，将字符串的大写字母
//转换为小写字母输出，其它字符直接输出

//错在哪里？
 
#include<stdio.h>
#include<string.h>

bool isChar(char);
void convert(char *);
void myStrupr(char *);
int main()
{
	//printf("%c",'a'-32);
	char a[]="I loVe You,Do you konW!";
	convert(a);
	return 0;
}

bool isChar(char a)
{
	return 'a'<=a&&a<='z'||'A'<=a&&a<='Z'?true:false;
}

void convert(char *a)
{
	puts(a);
	for(int i=0;i<strlen(a);i++)
		if(isChar(a[i]))
			myStrupr(&a[i]);
			
	puts(a);
}

void myStrupr(char *a)
{
	*a-=32;
}
