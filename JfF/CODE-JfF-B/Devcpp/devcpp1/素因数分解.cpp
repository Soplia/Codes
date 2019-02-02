/*
	Subject:�������ֽ� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-7-1 
	Date_Begin:13/01/17 19:31
	Date_End:
*/

#include <stdio.h>

const int size=10001;
//������� 
bool prime[size];
//����������� 
int ans=0;
//��Ÿ������� 
int ansE[30];
//��Ÿ���������Ӧ���� 
int ansP[30];

//Ԥ����ʹ��ɸѡ����ø������� 
void getP()
{
	for(int i=2;i<=size;i++)
		prime[i]=true;
		
	prime[1]=false;
	
	for(int i=2;i<=size;i++)
		if(prime[i])
			for(int j=2;i*j<=size;j++)
				prime[i*j]=false;
} 

void getAns(int x)
{
	if(x==1)
	{
		ansP[1]=1;
		ansE[1]=1;
		ans++;
	}
	else 
		for(int i=2;i<=x;i++)
		//������������ܱ����������Ԥ���� 
			if(prime[i]&&x%i==0)
			{
				ansP[++ans]=i;
				ansE[ans]=0;
				while(x%i==0)
				{
					ansE[ans]++;
					x/=i;
				}
			}
}

void display()
{
	int a=0;
	for(int i=1;i<=ans;i++)
	{
		printf("%d ",ansP[i]);
		a+=ansE[i];
	}
	printf("\n%d\n",a);
}

int main()
{
	getP();
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		ans=0;
		getAns(x);
		display();	
	}	
	return 0;
}

/*
��������
��������
120
�������
5
*/




















