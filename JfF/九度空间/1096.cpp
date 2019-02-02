/*
Subject:ÈÕÆÚ²îÖµ 
ID:1096
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 07:43
Result:Accepted
EndTime:16/03/17 07:49
*/

#include <stdio.h>

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

int myAbs(int x)
{
	return x>0?x:-x;
}

int main()
{
	pre();
	int d1,d2,m1,m2,y1,y2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",myAbs(day[y1][m1][d1]-day[y2][m2][d2])+1);
	}
	return 0;
}
/*
InputData:
20110412
20110422
OutputData:
11
*/


					  
					  
