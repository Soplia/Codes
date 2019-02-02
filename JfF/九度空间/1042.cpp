/*
Subject:最长公共子串 
ID:1042
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 19:59
Result:Accepted
EndTime:27/03/17 20:09
*/

#include <stdio.h>
#include <string.h>
#define N 101

char str1[N];
char str2[N];
int dp[N][N];

int max(int a,int b)
{
	if(a>b)	
		return a;
	else
		return b;
}

int main()
{
	while(gets(str1))
	{
		scanf("%s",str2);
		getchar();
		int len1=strlen(str1);
		int len2=strlen(str2);
		for(int i=0;i<len1;i++)
			dp[i][0]=0;
		for(int i=0;i<len2;i++)
			dp[0][i]=0;
			
		for(int i=0;i<len1;i++)
			for(int j=0;j<len2;j++)
				if(str1[i]==str2[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		
		printf("%d\n",dp[len1-1][len2-1]);
	}
	
	return 0;
}

/*
InputData:
abcd
cxbydz
OutputData:
2
*/

