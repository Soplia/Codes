/*
	Subject:Å’·‚ÌŒö‹¤i‚±‚¤‚«‚å‚¤j˜—ñ 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:7.4
	Date_Begin:04/02/17 11:43
	Result: Accepted
	Date_End:04/02/17 12:00
*/
#include <stdio.h>
#include <string.h>
#define N 100

int f[N][N];

void init()
{
	for(int i=0;i<N;i++)
	{
		f[i][0]=f[0][i]=0;
	}
}

void dis(int x,int y)
{
	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<=y;j++)
			printf("%-2d",f[i][j]);
		printf("\n");
	}
}

int main()
{
	char aa[N],bb[N];
	while(gets(aa))
	{
		gets(bb);
		init();
		for(int i=0;i<strlen(aa);i++)
			for(int j=0;j<strlen(bb);j++)
			{
				if(aa[i]==bb[j])
					f[i+1][j+1]=f[i][j]+1;
				else
					f[i+1][j+1]=(f[i][j+1]>f[i+1][j]?f[i][j+1]:f[i+1][j]);
			}
		//dis(a.size(),b.size());
		printf("%d\n",f[strlen(aa)][strlen(bb)]);
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





