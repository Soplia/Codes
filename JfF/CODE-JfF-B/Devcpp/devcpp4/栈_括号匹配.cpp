/*
	Subject:栈_括号匹配_自定义 
    Compiler:Devcpp
	Description:先建立一个结构体，压栈，但是压入的是地址。 
	Author:JiaruiXie
	Id:3-1-1
	Date_Begin:08/01/17 15:25
	Date_End:09/01/17 09:40
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack> 
#include <string.h>
using namespace std;

typedef struct c
{
	char data;
	char flag;
}Char;

int main()
{
	char s[100];
	while(gets(s))
	{
		int n=strlen(s);
		Char *a=(Char *)malloc(sizeof(Char)*n);
		for(int i=0;i<n;i++)
		{
			a[i].data=s[i];
			a[i].flag=' ';
		}
		
		stack<Char *> myS;
		 
		for(int i=0;i<n;i++)
			if(a[i].data=='(')
				myS.push(&a[i]);
			else if(a[i].data==')')
				if(myS.empty())
					a[i].flag='?';
				else if(!myS.empty())
				{
					Char *temp=myS.top();
					if(temp->data!='(')
					{
						temp->flag='$';
						a[i].flag='?';
					}
					else if(temp->data=='(')
						myS.pop();
				}
				
		while(!myS.empty())
		{
			Char *temp=myS.top();
			if(temp->data==')')
				temp->flag='?';
			else if(temp->data=='(')
				temp->flag='$';
			myS.pop();
		}
		
		for(int i=0;i<n;i++)
			printf("%c",a[i].data);
		printf("\n");
		for(int i=0;i<n;i++)
			printf("%c",a[i].flag);
		printf("\n");
	}
	
	return 0; 
} 
/*
测试数据
)(rttyy())sss)(
*/

/*
	else if(a[i].data=='}')
			{
				if(myS.empty())
					a[i].flag='?';
				else if(!myS.empty())
				{
					Char *temp=myS.top();
					if(temp->data!='{')
					{
						temp->flag='?';
						a[i].flag='$';
					}
					else if(temp->data=='{')
						myS.pop();
				}	
			}
			else if(a[i].data==']')
			{
				if(myS.empty())
					a[i].flag='?';
				else if(!myS.empty())
				{
					Char *temp=myS.top();
					if(temp->data!='[')
					{
						temp->flag='?';
						a[i].flag='$';
					}
					else if(temp->data=='[')
						myS.pop();
				}
			}
*/















 
