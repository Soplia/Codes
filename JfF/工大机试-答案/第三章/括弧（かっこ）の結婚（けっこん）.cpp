/*
Subject:括弧（かっこ）の結婚（けっこん） 
ID:3.1 
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 14:45
Result:Accepted
EndTime:05/02/17 15:05
*/
#include <stdio.h>
#include <string.h>
#include <stack>
#define N 200
using namespace std;

stack<int>myS;

int main()
{
	char a[N],b[N];
	
	while(scanf("%s",a)!=EOF)
	{
		while(!myS.empty())
			myS.pop();
		int len=strlen(a);
		
		for(int i=0;i<len;i++)
			if(a[i]=='(')
			{
				myS.push(i);
				b[i]=' ';
			}	
			else if(a[i]==')')
				if(!myS.empty())
				{
					myS.pop();
					b[i]=' ';
				}
				else
					b[i]='?';
			else
				b[i]=' ';
				
		//			
		while(!myS.empty())
		{
			int pos=myS.top();
			myS.pop();
			b[pos]='$';
		}
		b[len]=0;
		puts(a);
		puts(b);
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

