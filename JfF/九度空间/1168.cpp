/*
Subject:×Ö·û´®µÄ²éÕÒÉ¾³ı 
ID:1168
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 20:52
Result:Accepted
EndTime:27/03/17 21:31
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	char str[101];
	gets(str);
	string a=str;
	for(int i=0;i<a.size();i++)
	{
		a[i]=tolower(a[i]);
	}
	while(gets(str))
	{
		string b=str,c=b;
		for(int i=0;i<b.size();i++)
			b[i]=tolower(b[i]);
		int t=b.find(a,0);
		while(t!=string::npos)
		{
			c.erase(t,a.size());
			b.erase(t,a.size());
			t=b.find(a,t);
		}
		t=c.find(' ',0);
		while(t!=string::npos)
		{
			c.erase(t,1);
			t=c.find(' ',0);
		}
		cout<<c<<endl;
	}
}


/*
InputData:
in
#include 
int main()
{

printf(" Hi ");
}
OutputData:
#clude
tma()
{

prtf("Hi");
}
*/

