//公鸡5文钱买1只, 母鸡3文钱买1只, 小鸡1文钱买3只,
  //     用100文钱买100只鸡，问公鸡、母鸡、小鸡各有几只
#include<stdio.h>
int main()
{
	int count=0;
	for(int i=1;i<=20;i++)
		for(int j=1;j<=33;j++)
			for(int k=3;k<=100;k+=3)
				if(i*5+j*3+k/3==100&&(i+j+k)==100)
				{
					printf("%3d%3d%3d\n",i,j,k);
					count++;
				}
	printf("%d\n",count);
	return 0;
}
