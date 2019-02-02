/*
Subject:括号匹配问题 
ID:1153
Complier:Devcpp
Author:JiaruiXie
StartTime:17/03/17 08:29
Result:Accepted
EndTime:17/03/17 09:04
*/

#include <stdio.h>
#include <stack> 
#include <string.h>
#define N 200
using namespace std;

char ret[N];
char str[N];
stack<int>myS;

int main()
{
	while(gets(str))
	{
		int len=strlen(str);
		int i;
		for(i=0;i<len;i++)
		{
			if(str[i]=='(')
			{
				myS.push(i);
				//这一句话，不加作用真的很大吗，
				//下载好codeblocks后进行认真的调试
				//弄明白这句话的作用 
				//如果不在这里加上这句话，那么就要在删除右括号
				//的时候加上这句话 
				ret[i]=' ';
			}
			else if(str[i]==')')
				if(myS.empty())
					ret[i]='?';
				else 
				{
					ret[i]=' ';
					//就像是这样，但这样太麻烦了 
					//int temp=myS.top();
					//ret[temp]=' ';
					myS.pop();
				}
			else
				ret[i]=' ';
		}
		while(!myS.empty())
		{
			ret[myS.top()]='$';
			myS.pop();
		}
		
		ret[i]=0;
		puts(str);
		puts(ret);
	}
	return 0;
}

/*
InputData:
)(rttyy())sss)(
OutputData:
)(rttyy())sss)(
?            ?$
*/

