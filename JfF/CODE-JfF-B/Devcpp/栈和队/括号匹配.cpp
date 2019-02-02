#include <iostream>
#include <iomanip>
#include "2.cpp"
using namespace std;
bool match(char a,char b)
{
	switch(a)
	{
		case'(':return b==')';
		case'[':return b==']';
		case'{':return b=='}';
		default:return false;
	}
}
char charAt(string str,int a)
{
	if(a<str.length())
		return str[a];
}
int main()
{
	string inputString;
	cout<<"Input a string:"<<endl;
	cin>>inputString;
	int length=inputString.length();
	int i=0;
	stack<char> *myStack=new stack<char>(); 
	while(i<length)
	{
		char a=charAt(inputString,i);
		if(a=='('||a=='['||a=='{')
			myStack->insert(a);
		else if(a==')'||a==']'||a=='}')
		{
			if(myStack->isEmpty())
			{
				cout<<"ÓÒÀ¨ºÅÊ£Óà!"<<endl;
				return 0;
			}	
			else
			{
				char d=myStack->remove();
				if(!match(d,a))
				{
					cout<<"À¨ºÅ²»Æ¥Åä:"<<d<<a<<endl;
					return 0;
				}	
			} 
		} 
		i++;
	}
	if(myStack->isEmpty())
		cout<<"À¨ºÅÆ¥Åä!"<<endl;
	else
		cout<<"×óÀ¨ºÅÊ£Óà!"<<endl;
	return 0;
}
















