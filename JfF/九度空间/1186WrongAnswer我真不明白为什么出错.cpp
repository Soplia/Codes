/*
Subject:打印日期 
ID:1186
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 08:16
Result:WrongAnswer 
EndTime:16/03/17 08:35
*/

#include <stdio.h>

int dayOfMonth[13][2]={
						0,0,
						31,31,
						28,29,
						31,31,
						30,30,
						31,31,
						30,30,
						31,31,
						31,31,
						30,30,
						31,31,
						30,30,
						31,31
					  };
					  
int isYear(int x)
{
	if(x%100!=0&&x%4==0||x%400==0)
		return 1;
	return 0;
}

int main()
{
	int d,m,y,t;
	while(scanf("%d%d",&y,&t)!=EOF)
	{
		for(int i=1;;i++)
		//这个地方需要特别注意
		//如果是包含等于号的话，可能会产生0日期 
			if(t>dayOfMonth[i][isYear(y)])
				t-=dayOfMonth[i][isYear(y)];
			else
			{
				m=i;
				d=t;
				break;
			}
		
		printf("%d-%02d-%02d\n",y,m,d);
	}
	return 0;	
} 

/*
InputData:
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60
OutputData:
2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01
*/

