/*
Subject:Digital Roots
ID:1124
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 09:21
Result:Accepted
EndTime:29/03/17 09:14
*/
//�������Ĵ���֮�����ں����˴���������
//������⿴��ȥҪдһ���󾫶���������ʵ����
//ֻ��Ҫʹ��һ������ͺ��� 
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

