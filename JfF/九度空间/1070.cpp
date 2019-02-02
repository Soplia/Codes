/*
Subject:今年的第几天 
ID:1070
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 08:10
Result:Accepted
EndTime:16/03/17 08:16
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
					  
bool isYear(int x)
{
	if(x%100!=0&&x%4==0||x%400==0)
		return true;
	return false;
}

int main()
{
	int d,m,y;
	while(scanf("%d%d%d",&y,&m,&d)!=EOF)
	{
		int cnt=0;
		for(int i=1;i<m;i++)
			cnt+=dayOfMonth[i][isYear(y)];
		cnt+=d;
		printf("%d\n",cnt);
	}
	return 0;	
} 
/*
InputData:
1990 9 20
2000 5 1
OutputData:
263
122
*/

