/*
	Subject:ɾ���ַ��� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:8-1-1
	Date_Begin:21/01/17 17:06
	Date_End:21/01/17 17:46
*/
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#define N 100
using namespace std;

int main()
{
	string str1;
	char c1[N];
	//�õ�Ŀ���ַ��� 
	gets(c1);
	str1=c1;
	for(int i=0;i<str1.size();i++)
		str1[i]=tolower(str1[i]);
	while(gets(c1))
	{
		string str2,str3;
		str2=c1;
		str3=str2;
		//ɾ����ͬ���ַ��� 
		for(int i=0;i<str3.size();i++)
			str3[i]=tolower(str3[i]);
			
		int pos=str3.find(str1,0);
		while(pos!=string::npos)
		{
			str2.erase(pos,str1.size());
			str3.erase(pos,str1.size());
			pos=str3.find(str1,pos);
		}
		//ɾ������Ŀո�
		pos=str2.find(' ',0);
		while(pos!=string::npos)
		{
			str2.erase(pos,1);
			pos=str2.find(' ',0);
		}
		cout<<str2<<endl;
	}
	return 0;
}

/*
��������
��������
in
#include 
int main()
{

printf(" Hi ");
}
�������
#clude
tma()
{

prtf("Hi");
}
*/



























