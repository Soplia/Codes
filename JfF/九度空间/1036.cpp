/*
Subject:Old Bill
ID:1036
Complier:Devcpp
Author:JiaruiXie
StartTime:26/03/17 08:24
Result:Accepted
EndTime:26/03/17 08:54
*/

#include <stdio.h>

int main()
{
	int n,x,y,z;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d%d%d",&x,&y,&z);
		int flag=true;
		int i,j,temp;
		//��Ϊ��ĿҪ�����ĵ���
		//���ԴӴ���С��ʼö�� 
		for(i=9;i>=0;i--)
		{
            for(j=9;j>=0;j--)
			{
				temp=i*10000+x*1000+y*100+z*10+j;
				//���ÿα��ϵļ��� 
				if((float)temp/n==temp/n)
				{
					flag=false;
					break;
				}
			}
			//Ҫ�ǽ����жϣ���Ҫ��i,j���в���֮ǰ�����ж� 
			if(!flag)
                break;
		}

		if(flag)
			puts("0");
		else
			printf("%d %d %d\n",i,j,temp/n);
	}
	return 0;
}

/*
InputData:
72
6 7 9
5
2 3 7
78
0 0 5
OutputData:
3 2 511
9 5 18475
0
*/

