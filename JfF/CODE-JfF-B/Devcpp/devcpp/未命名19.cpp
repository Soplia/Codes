//����5��Ǯ��1ֻ, ĸ��3��Ǯ��1ֻ, С��1��Ǯ��3ֻ,
  //     ��100��Ǯ��100ֻ�����ʹ�����ĸ����С�����м�ֻ
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
