/*
Subject:Day of Week
ID:1043
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 07:50
Result:Accepted
EndTime:16/03/17 08:09
*/

#include <stdio.h>
#include <string.h>

int day[5001][13][32];

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

char weekName[][20]={
						"Monday","Tuesday","Wednesday","Thursday","Friday",
						"Saturday","Sunday"
					};
					
char monthName[][20]={
						"","January","February","March","April","May","June","July",
						"August","September","October","November","December"
					 }; 
 
bool isYear(int x)
{
	if(x%100!=0&&x%4==0||x%400==0)
		return true;
	return false;
}

void pre()
{
	int d=0,m=1,y=0,cnt=0;
	while(y!=5000)
	{
		d++;
		cnt++;
		if(d>dayOfMonth[m][isYear(y)])
		{
			d=1;
			m++;
			if(m>12)
			{
				m=1;
				y++;
			}
		}
		day[y][m][d]=cnt;
	}
}

int main()
{
	pre();
	char m1[20];
	int d,m,y;
	while(scanf("%d%s%d",&d,m1,&y)!=EOF)
	{
		for(int i=1;i<13;i++)
			if(strcmp(monthName[i],m1)==0)
			{
				m=i;
				break;
			}
		
		int ret=day[y][m][d]-day[2017][3][16]+3;
		ret=((ret%7)+7)%7;
		printf("%s\n",weekName[ret]);
	}
	return 0;
}

/*
InputData:
9 October 2001
14 October 2001
OutputData:
Tuesday
Sunday
*/

