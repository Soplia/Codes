/*
Subject:����ƥ������ 
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
				//��һ�仰������������ĺܴ���
				//���غ�codeblocks���������ĵ���
				//Ū������仰������ 
				//����������������仰����ô��Ҫ��ɾ��������
				//��ʱ�������仰 
				ret[i]=' ';
			}
			else if(str[i]==')')
				if(myS.empty())
					ret[i]='?';
				else 
				{
					ret[i]=' ';
					//������������������̫�鷳�� 
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

