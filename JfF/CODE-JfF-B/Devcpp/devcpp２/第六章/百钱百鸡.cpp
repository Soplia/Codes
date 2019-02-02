/*
	Subject:百钱百鸡 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6-1-1 
	Date_Begin:19/01/17 15:13
	Date_End:19/01/17 15:27
*/
#include <stdio.h> 

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int x=0;x<=100;x++)
			for(int y=0;y<=100;y++)
				{
					int z=100-x-y;
					if(15*x+9*y+z<=3*n)
						printf("x=%d,y=%d,z=%d\n",x,y,z);
				}
	}		
	return 0;
}
/*
测试数据
样例输入
40
样例输出
x=0,y=0,z=100
x=0,y=1,z=99
x=0,y=2,z=98
x=1,y=0,z=99
*/

