#include <iostream>
#include <iomanip>
#include "1.cpp"
using namespace std;

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
	int i=0,length=inputString.length();
	stack<double> *myStack=new stack<double>();
	while(i<length)
	{
		char c=charAt(inputString,i);
		if(c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!=' ')
		{
			myStack->insert((int)c-48);
		}
		if(c=='+'||c=='-'||c=='*'||c=='/')
		{
			double left,right;
			right=myStack->remove();
			left=myStack->remove();
			switch(c)
			{
				case '+':myStack->insert(left+right);break;
				case '-':myStack->insert(left-right);break;
				case '*':myStack->insert(left*right);break;
				case '/':myStack->insert(left/right);break;
				default:myStack->insert(0);break;
			}
		}
		i++;
	}
	cout<<myStack->remove();
	return 0;
}


























