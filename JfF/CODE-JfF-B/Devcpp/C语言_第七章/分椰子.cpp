/*
  	Subject:分椰子 
	ID:7.8 
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 17:49
	EndTime:31/01/17 18:25
*/
#include <stdio.h>

int count(int n)
{
	int x=1;
	int i=1;
	float y=n*x+1;
	do
	{
		y=y*n/(n-1)+1;
		i++;
		if(y!=int(y))
		{
			x++;
			y=n*x+1;
			i=1;
		}
	}while(i<n);
	//要返回第一次时候总的椰子数。
	//而x是第五次均分5堆是的椰子数 
	return (int)y;	
}

int main()
{
	printf("%d\n",count(5)); 
	return 0;
}



















