/*
	Subject:在每个字符之间插入一个空格 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:10.6
	Date_Begin:17/01/17 11:09
	Date_End:
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 1000

char str[N];

char *insertC(char *a);

int main()
{
	fgets(str,N,stdin);
	puts(insertC(str));
	return 0;
}

char *insertC(char *a)
{
	char b[N];
	for(int i=0;i<N;i++)
		b[i]='*';
	int i=0;	
	bool flag=true;
	
	for(char *p=str;*p!=0;p++)
		if(!isalpha(*p))
		{
			b[i]=*p;
			i++;
			flag=false;
		}
		else
		{
			if(flag)
			{
				i++;
				b[i++]=*p;
			}
			if(!flag)
			{
				b[i++]=*p;
				flag=true;
			}	
		}
		
		
	return b;
}


/*
测试数据
样例输入
i miss you   do you miss me  
样例输出

*/






















