/*
	Subject:排版_叠筐 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:2-4-2
	Date_Begin:07/01/17 12:22
	Date_End:07/01/17 14:03
*/

#include <stdio.h>

int main()
{
	char s[83][83];
	int n;
	char a,b;
	while(scanf("%d %c %c",&n,&a,&b)==3)
	{
		//i作为筐的边长，j作为循环次数标志 
		for(int i=1,j=1;i<=n;i+=2,j++)
		{
			int x=n/2+1;
			//确定要使用的赋值字符
			char c=j%2==0?b:a; 
			//确定每一次循环的顶点 
			x=x-j+1;
			int y=x;
			//为每一圈进行赋值
			for(int k=0;k<i;k++)
			{
				s[x][y+k]=c;
				s[x+k][y]=c;
				s[x+i-1][y+k]=c;
				s[x+k][y+i-1]=c;
			} 
			
		}
		//四个角赋值为空格 
		s[1][1]=s[1][2]=' ';
		s[n][1]=s[n][2]=' ';
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%c",s[i][j]);
			printf("\n\n");
		}
			
	}
	return 0;
}


























