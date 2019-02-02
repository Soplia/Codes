// 444.cpp : Defines the entry point for the console application.
//

//3#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int x,y,comp,result,temp;
	char ch,choice;
	srand(time(0));
	do
	{
		system("cls");
		x=rand()%100;
		y=rand()%100;
		if(rand()%2==0)
		{
			ch='-';
			if(x<y)
			{
				temp=x;
				x=y;
				y=temp;
			}
		}
		else
			ch='+';
		printf("\n%d%c%d=",x,ch,y);
		scanf("%d",&result);
		getchar();
		if(ch=='-')
			comp=x-y;
		else
			comp=x+y;
		if(result==comp)
			printf("答案正确，非常好！\n");
		else
		{
			printf("答案错误，再来一次！\n");
			printf("\n%d%c%d=",x,ch,y);
			//scanf("%d",result);
			scanf("%d",&result);
			getchar();
			if(result==comp)
				printf("答案正确，非常好！\n");
			else 
				printf("答案错误，%d%c%d=%d\n",x,ch,y,comp);
		}
		printf("还要继续吗？(y/n)\n");
		choice=getchar();
	}while(choice=='y'||choice=='Y');
	//while(choice='y'||choice=='Y');
	return 0;
}

