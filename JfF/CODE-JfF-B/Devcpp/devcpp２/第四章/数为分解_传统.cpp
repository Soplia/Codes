/*
	Subject:%��Ӧ�� 
    Compiler:Devcpp
	Description:����˷����������ĸ�����λ��� 
	Author:JiaruiXie
	Id:4-2-1 
	Date_Begin:11/01/17 19:00
	Date_End:11/01/17 19:12
*/
#include <stdio.h>

int main()
{
	int sizeA,sizeB;
	int a[10],b[10];
	int aa,bb;
	while(scanf("%d",&aa)!=EOF)
	{
		scanf("%d",&bb);
		sizeA=0;
		sizeB=0;
		while(aa/10!=0)
		{
			a[sizeA++]=aa%10;
			aa/=10; 
		}
		a[sizeA]=aa;
		while(bb/10!=0)
		{
			b[sizeB++]=bb%10;
			bb/=10; 
		}
		b[sizeB]=bb;
		int ans=0;
		for(int i=0;i<=sizeA;i++)
			for(int j=0;j<=sizeB;j++)
				ans+=(a[i]*b[j]);
		printf("%d\n",ans);
	}
	return 0;
} 
/*
��������
��������
123 45
�������
54 
*/


























