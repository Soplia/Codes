/*
Subject:�����ھ�	 
ID:1450
Complier:Devcpp
Author:JiaruiXie
StartTime:28/03/17 08:58
Result:Accepted
EndTime:28/03/17 09:33
*/
//Ϊʲô��map<string,int>����map<char *,int>�ͻ���ִ��󣿣�
//������Ҳ����׵ĵط��� 
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
		//����ط����ж�����Ҫ������ϸ���ǣ�
		//��Ϊ�ɹ�ֻ��һ�ֿ��ܣ�����ʧ���ж��ֿ���
		//������Ϊֻ��һ�ֿ��ܣ���ôֱ�ӽ�����ȷ�����ˡ� 
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

