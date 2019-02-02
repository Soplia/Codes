/*
Subject:diekuang
ID:2.8
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 10:45
Result:Accepted
EndTime:08/02/17 14:18
*/
#include <stdio.h>
#define N 90

char array[N][N];

int main()
{
	int n;
	char a,b,temp;
	int flag=1;
	while(scanf("%d %c %c",&n,&a,&b)!=EOF)
	{
		
		if(flag)
			flag=0;
		else
			printf("\n");
			
		int cnt=(n+1)/2;
		for(int line=1;line<=(n+1)/2;line++)
		{
			temp=(cnt&1)==1?a:b;
			for(int i=line;i<=n-line+1;i++)	
			{
				array[line][i]=array[n+1-line][i]=temp;
				array[i][line]=array[i][n+1-line]=temp;
			} 
			cnt--;
		}
		
		if(n!=1)
		{
			array[1][1]=array[n][1]=' ';
			array[1][n]=array[n][n]=' ';
		}
	
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%c",array[i][j]);
			printf("\n");
		}
	}
}
/*
InputData:
11 B A
5 @ W
OutputData:
 AAAAAAAAA
ABBBBBBBBBA
ABAAAAAAABA
ABABBBBBABA
ABABAAABABA
ABABABABABA
ABABAAABABA
ABABBBBBABA
ABAAAAAAABA
ABBBBBBBBBA
 AAAAAAAAA
 
 @@@
@WWW@
@W@W@
@WWW@
 @@@
*/

