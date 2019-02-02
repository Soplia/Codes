/*
Subject:Tr A 
ID:121/03/17 07:55
Complier:Devcpp
Author:JiaruiXie
StartTime:
Result:
EndTime:
*/

#include <stdio.h>
#include <string.h>
#define N 202

int a1[N],a2[N],b1[N],b2[N]; 
int s1,s2,s3,s4;
char aa[N],bb[N];

int main()
{
	while(gets(aa))
	{
		gets(bb);
		int pos1,pos2;
		for(int i=0;aa[i]!=0;i++)
			if(aa[i]=='.')
			{
				pos1=i;
				break;
			}	
		for(int i=0;bb[i]!=0;i++)
			if(bb[i]=='.')
			{
				pos2=i;
				break;
			}
				
				
	}
	return 0;
}

/*
InputData:
2
2 2
1 0
0 1
3 99999999
1 2 3
4 5 6
7 8 9
OutputData:
2
2686
*/

