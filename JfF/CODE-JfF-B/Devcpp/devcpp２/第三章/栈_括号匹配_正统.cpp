/*
	Subject:ջ_����ƥ��_��ͳ 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:3-1-2
	Date_Begin:09/01/17 09:45
	Date_End:09/01/17 09:58
*/

#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	int n;
	char a[100];
	char s[100];
	int i=0;
	stack<char >S;
	while(scanf("%s",a)!=EOF)
	{
		for(;a[i]!=0;i++)
		{
			if(a[i]=='(')
			{
				//�ؼ��ڴˣ���ջ��ѹ�����±� 
				S.push(i);
				s[i]=' ';
			}
			else if(a[i]==')')
			{
				if(S.empty())
					s[i]='?';
				else
				{
					S.pop();
					s[i]=' ';
				}
			}
			else
				s[i]=' ';
		}
		while(!S.empty())
		{
			s[S.top()]='$';
			S.pop();
		}
		//�γ��ַ��� 
		s[i]=0;
		puts(a);
		puts(s);
	}
	return 0;
}

/*
��������
)(rttyy())sss)(
*/



















