/*
	Subject:ö�������� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-6-2 
	Date_Begin:11/01/17 21:14
	Date_End:11/01/17 21:58
*/
#include <stdio.h>
bool a[10001];
int main()
{	
	int n;
	bool isOutput; 
	while(scanf("%d",&n)!=EOF)
	{
		//��û�к��ʵ�����ʱ�����-1 
		isOutput=false;
		for(int i=1;i<=n;i++)
			a[i]=true;
		a[1]=false;
		
		//���д��for(int i=2;i<=n&&a[i];i++)
		//�Ǵ�ģ�ӦΪһ��!a[i]������ѭ������ֹ�� 
		for(int i=2;i<=n;i++)
		{
			if(a[i])
				for(int j=2;i*j<=n;j++)
					a[i*j]=false;
		}
		
		for(int i=2;i<=n;i++)
		//ע�ⲻҪʹ��a[i]%10==1�������ж� 
			if(a[i]&&i%10==1)
			{
				if(!isOutput)
				{
					isOutput=true;
					printf("%d",i);
				}
				else
					printf(" %d",i);
			}
		if(!isOutput)
			printf("-1\n");		
		else
			printf("\n");
	}
	return 0;
}
/*
��������
��������
100
5
�������
11 31 41 61 71
-1
*/

