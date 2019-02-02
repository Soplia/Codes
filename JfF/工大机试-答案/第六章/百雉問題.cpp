/*
	Subject:•Sè³–â‘è 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.1
	Date_Begin:02/02/17 20:03
	Result:Accepted
	Date_End:05/02/17 11:36
*/
#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<=n/5;i++)
			for(int j=0;j<=n/3;j++)
			{
				int temp=100-i-j;
				if(i*15+j*9+temp<=3*n)
					printf("x=%d,y=%d,z=%d\n",i,j,temp);
			}
	}
	return 0;
}

/*
InputData:
40
outputData:
x=0,y=0,z=100
x=0,y=1,z=99
x=0,y=2,z=98
x=1,y=0,z=99
*/

