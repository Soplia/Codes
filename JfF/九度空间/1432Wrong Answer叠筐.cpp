/*
Subject:µþ¿ð 
ID:1432
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 09:16
Result:Wrong Answer
EndTime:16/03/17 09:35
*/

#include <stdio.h>
#include <stdlib.h>
#define N 100

char ans[N][N];

int main()
{
	char f,e;
	int size;
	while(scanf("%d %c %c",&size,&f,&e)!=EOF)	
	{
		getchar();
		int a=(size+1)/2;
		bool flag=true;
		char t;
		for(int i=a;i>=1;i--)
		{
			if(flag)
				t=f;
			else
				t=e;
				
			int cnt=(a-i)*2+1;
			
			for(int j=0;j<cnt;j++) 
			{
				ans[i+cnt-1][i+j]=ans[i][i+j]=t;
				ans[i+j][i]=ans[i+j][i+cnt-1]=t;
			}
			flag=!flag;	
		}
		
		if(size==1)
			printf("%c\n",ans[size][size]);
		else
		{
			ans[1][1]=ans[1][size]=' ';
			ans[size][1]=ans[size][size]=' ';
			
			for(int i=1;i<=size;i++)
			{
				for(int j=1;j<=size;j++)
					printf("%c ",ans[i][j]);
				printf("\n");					
			}
		}
	}
	return 0;
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

