/*
	Subject：文字列（もじれつ）が削り取る（けずりとる） 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:8.1 
	Date_Begin:03/02/17 17:12
	Result:Accepted
	Date_End:04/02/17 10:01
*/

#include <ctype.h>
#include <stdio.h> 
#include <iostream>
#include <string>
using namespace std;

int main()
{ 
	char a[100];
	string aim;
	string orS;
	string coS;
	
	gets(a);
	aim=a;
	for(int i=0;i<aim.size();i++)
		aim[i]=tolower(aim[i]);
	//cout<<"*"<<aim<<"*"<<endl;
	char temp[100];
	while(gets(temp))
	{
		//cout<<"hello"<<endl;
		coS=temp;
		orS=temp;
		
		for(int i=0;i<coS.size();i++)
			coS[i]=tolower(coS[i]);
		
		//cout<<"world"<<endl;
		int startPos=coS.find(aim,0);
		//cout<<startPos<<endl;
		
		while(startPos!=string::npos)
		{
			//cout<<startPos<<" "<<aim.size()<<endl; 
			coS.erase(startPos,aim.size());
			orS.erase(startPos,aim.size());
			startPos=coS.find(aim,startPos);
		}
		startPos=orS.find(' ',0);
		while(startPos!=string::npos)
		{
			orS.erase(startPos,1);
			startPos=orS.find(' ',0);
		}
		cout<<orS<<endl;
	}
	return 0;
}

/*
InputData:
in
#include
int main()
{


printf(" Hi ");
}
outputData:
#clude
tma()
{


prtf("Hi");
}
*/



