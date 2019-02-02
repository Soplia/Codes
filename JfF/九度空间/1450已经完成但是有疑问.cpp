/*
Subject:产生冠军	 
ID:1450
Complier:Devcpp
Author:JiaruiXie
StartTime:28/03/17 08:58
Result:Accepted
EndTime:28/03/17 09:33
*/
//为什么将map<string,int>换成map<char *,int>就会出现错误？？
//这个是我不明白的地方。 
#include <stdio.h>
#include <map>
#include <string>
#define N 50
using namespace std;

char f[N],r[N];
string rr,ff;
int ans[2002];
int num;
map<string,int> M;

void pre()
{
	M.clear();
	num=0;
	for(int i=0;i<2002;i++)
		ans[i]=0;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		pre();
		
		while(n--)
		{
			scanf("%s%s",f,r);
			rr=r;
			ff=f;
//			if(M.find(f)==M.end())
//				M[f]=num++;
//			if(M.find(r)==M.end())
//				M[r]=num++;
//			ans[M[r]]++;
			if(M.find(ff)==M.end())
				M[ff]=num++;
			if(M.find(rr)==M.end())
				M[rr]=num++;
			ans[M[rr]]++;
		}
		
		int ret=0;
		for(int i=0;i<num;i++)
			if(ans[i]==0)
				ret++;
		//这个地方的判断条件要进行详细考虑，
		//因为成功只有一种可能，但是失败有多种可能
		//所以因为只有一种可能，那么直接进行明确就行了。 
		if(ret==1)
			puts("Yes");
		else
			puts("No");
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

