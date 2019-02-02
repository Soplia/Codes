/*
	Subject:DP_最长公共子序列的长度 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:7-3-1 
	Date_Begin:21/01/17 16:35
	Date_End:21/01/17 16:43
*/
#include <stdio.h>
#include <string.h>
#define N 100

char s1[N],s2[N];
int dp[N][N];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		int l1=strlen(s1);
		int l2=strlen(s2);
		for(int i=0;i<l1;i++)
			dp[i][0]=0;
		for(int i=0;i<l2;i++)
			dp[0][i]=0;
			
		for(int i=1;i<l1;i++)
			for(int j=1;j<l2;j++)
			{
				if(s1[i]==s2[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else if(s1[i]!=s2[j])
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		printf("%d\n",dp[l1-1][l2-1]);
	} 
	return 0;
}

/*
测试数据
样例输入
abcd
cxbydz
样例输出
2
*/




















