/*
	Subject:優勝者（ゆうしょうしゃ） が生ずる（しょうずる） 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:8.2 
	Date_Begin:04/02/17 10:01
	Result:Accepted 
	Date_End:04/02/17 10:19
*/
#include <stdio.h>
#include <map>
#include <string>
#define N 2000
using namespace std;

int inD[N];
map<string,int> m;
int id;

void init()
{
	for(int i=0;i<N;i++)
		inD[i]=0;
	id=0;
	m.clear();
}

void dis(int x)
{
	for(int i=1;i<=x;i++)
		printf("%-2d",inD[i]);
	printf("\n");
}

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF&&size!=0)
	{
		init();
		int temp=size;
		while(size--)
		{
			char a[10],b[10];
			scanf("%s%s",a,b);
			if(m.find(a)==m.end())
				m[a]=++id;
			if(m.find(b)==m.end())
			{
				m[b]=++id;
				inD[m[b]]++;
			}
				
			else
			{
				int pos=m[b];
				inD[pos]++;
			}
			//dis(id);
		}
		
		int ans=0;
		for(int i=1;i<=id;i++)
			if(inD[i]==0)
				ans++;
		if(ans==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

/*
InputData:
3
Alice Bob
Smith John
Alice Smith
5
a c
c d
d e
b e
a d
0
OutputData:
Yes
No
*/


