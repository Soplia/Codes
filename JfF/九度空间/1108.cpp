/*
Subject:堆栈的使用 
ID:1108
Complier:Devcpp
Author:JiaruiXie
StartTime:17/03/17 09:10
Result:WrongAnswer 
EndTime:
*/
 
#include <stdio.h>
#include <stack> 
using namespace std;

stack<int>myS;

int main()
{
	int n;
	char temp,num;
	//处理字符好麻烦 
	//codeblocks下载完成之后进行认真的调试 
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(int i=0;i<n;i++)
		{
			scanf("%c",&temp);
			switch(temp)
			{
				case 'P':
					{
						
						scanf("%d",&num);
						myS.push(num);
					};break;
				case 'A':
					{
						if(!myS.empty())
							printf("%d\n",myS.top());
						else
							puts("E");
					};break;
				case 'O':
					{
						if(!myS.empty())
							myS.pop();
					};break;
			}
		}
		printf("\n");
	}
	return 0;
}

/*
InputData:
3
A
P 5
A
4
P 3
P 6
O 
A
0
OutputData:
E
5

3
*/

