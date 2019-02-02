#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
	char temp[100];
	string aim,coS,orS;
	gets(temp);
	aim=temp;
	for(int i=0;i<aim.size();i++)
		aim[i]=tolower(aim[i]);
		
	while(gets(temp))
	{
		coS=orS=temp;
		for(int i=0;i<coS.size();i++)
			coS[i]=tolower(coS[i]);
		int startPos=coS.find(aim,0);
		while(startPos!=string::npos)
		{
			coS.erase(startPos,aim.size());
			orS.erase(startPos,aim.size());
			startPos=coS.find(aim,startPos);
		}
		
		startPos=coS.find(' ',0);
		while(startPos!=string::npos)
		{
			coS.erase(startPos,1);
			orS.erase(startPos,1);
			startPos=coS.find(' ',0);
		}
		
		cout<<orS<<endl;
	}
	return 0;
}
