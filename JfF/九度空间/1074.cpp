/*
Subject:�Գ�ƽ���� 
ID:1074
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 09:15
Result:Accepted
EndTime:20/03/17 09:20
*/

#include <stdio.h>
#include <string.h>
#define N 10

char aa[N];

int main()
{
	for(int i=0;i<256;i++)
	{
		int flag=1;
		int temp=i*i;
		sprintf(aa,"%d",temp);
		for(int k=0,j=strlen(aa)-1;k<j;k++,j--)
			if(aa[k]!=aa[j])
			{
				flag=0;
				break;
			}
		if(flag)
			printf("%d\n",i);
	}
	return 0;
}

/*
InputData:
���κ���������
OutputData:
���������ĿҪ������ʵ��������������ݲ�ֹһ�飬��������֮���Իس�������
*/

