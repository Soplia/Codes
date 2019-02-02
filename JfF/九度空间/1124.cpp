/*
Subject:Digital Roots
ID:1124
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 09:21
Result:Accepted
EndTime:29/03/17 09:14
*/
//这个问题的错误之处在于忽略了大整数问题
//这个问题看上去要写一个大精度整数，但实际上
//只需要使用一个数组就好了 
#include <stdio.h>
#include <string.h>
#define N 1000

char dig[N];

int main()
{
	while(scanf("%s",dig)!=EOF)
	{
		long long ans;
		int len=strlen(dig);
		if(len==1&&dig[0]=='0')
			break;

		while(len>1)
		{
			ans=0;
			for(int i=0;i<len;i++)
				ans+=dig[i]-'0';
			sprintf(dig,"%d",ans);
			len=strlen(dig);
		}

		printf("%d\n",dig[0]-'0');
	}
	return 0;
}

/*
InputData:
24
39
0
OutputData:
6
3
*/

