#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000001;
const int INF=1e9+6;
int list[maxn],dp[maxn];

int main()
{
    int n,t;
    while (scanf("%d%d", &n, &t) != EOF)
	{
		int size = n * t;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &list[i]);
			dp[i]=INF;
		}
			
		for (int i = 1; i < t; i++)
			for (int j = 0; j < n; j++)
			{
				int t = i * n + j;
				list[t] = list[j];
				dp[t]=INF;
			}
				
				
       
        for(int i=0;i<size;i++)
        {
            int p=lower_bound(dp,dp+n,list[i])-dp;
            dp[p]=list[i];
        }
        cout<<upper_bound(dp,dp+n,INF)-dp<<endl;
    }
    return 0;
}

