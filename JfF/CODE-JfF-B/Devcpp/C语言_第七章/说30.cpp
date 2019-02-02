/*
  	Subject:说30 
	ID:7.11
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 17:17
	EndTime:
*/
#include <stdio.h>
#include <stdlib.h>
#define N 50

int array[N];
int count;

void computerSet()
{
	//报一个数 
	if(count%3==1)
		array[count--]=1;
	//报两个数 
	else if(count%3==2)
		array[count--]=array[count--]=1;
	//为奇数报一个 
	else if(((rand()%100+1)&1)==1)
		array[count--]=1;
	//为偶数报两个 
	else
		array[count--]=array[count--]=1;	 
}

void display()
{
	for(int i=30,j=1;i>count;i--,j++)
		printf("%3d",j);
	printf("\n");
}

int main()
{
	count=30;
	srand(0);
	int size;
	while(count>=1)
	{
		scanf("%d",&size);	
		if(size==1)
			array[count--]=1;
		else if(size==2)
			array[count--]=array[count--]=1;
		display();
		if(count==0)
		{
			printf("用户获得胜利\n");
			break; 
		} 
			
		computerSet();
		display();
		if(count==0)
		{
			printf("计算机获得胜利\n");
			break;
		}
			
		
	} 
	return 0;
}


















