/*
  	Subject:ËãÄêÁä 
	ID:7.9
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 17:08
	EndTime:31/01/17 17:17
*/
#include <stdio.h>

int get(int x)
{
	if(x==1)
		return 10;
	else
		return get(x-1)+2;
}

int main()
{
	printf("%d\n",get(5));
	return 0;
}
