/*
	Subject:MAP_产生冠军 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:8-2-1
	Date_Begin:21/01/17 17:59
	Date_End:21/01/17 20:02
*/
#include <stdio.h>
#include <string>
#include <map>

#define N 1000
using namespace std;

int in[N];
map<string,int> myMap;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int id=0;
		myMap.clear();
		for(int i=0;i<n*2;i++)
			in[i]=0;
		char c1[N/10],c2[N/10];
		string str1,str2;
		for(int i=0;i<n;i++)
		{
			scanf("%s%s",c1,c2);
			str1=c1;
			str2=c2;
			int idb;
			if(myMap.find(str1)==myMap.end())
				myMap[str1]=id++;
			if(myMap.find(str2)==myMap.end())
			{
				idb=id;
				myMap[str2]=id++;
			}
			else
				idb=myMap[str2];
			in[idb]++;
		}
		int ans=0;
		for(int i=0;i<id;i++)
			if(in[i]==0)
				ans++;
		printf("%s\n",ans==1?"Yes":"No");
	}
	return 0;
}

/*
测试数据
样例输入
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
样例输出
Yes
No
*/





























