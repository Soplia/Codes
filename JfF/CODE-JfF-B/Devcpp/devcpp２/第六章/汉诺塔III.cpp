/*
	Subject:��ŵ��III 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6-3-1 
	Date_Begin:19/01/17 16:59
	Date_End:19/01/17 17:12
*/
#include <stdio.h>

int f(int x)
{
	if(x==1)
		return 2;
	else 
		return 3*f(x-1)+2;
}

void move(int ,char ,char);
void han(int ,char,char ,char);

int main()
{
	
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		han(x,'A','B','C');
		printf("���ƶ�����=%d\n",f(x));
	}
	return 0;
}

void move(int d,char a,char b)
{
	printf("���� %d ��Բ�̴� %c Բ̨�ƶ��� %c Բ̨\n",d,a,b);
}

void han(int d,char a,char b,char c)
{
	if(d==1)
	{
		move(d,a,b);
		move(d,b,c);
	}
	else
	{
		han(d-1,a,b,c);
		move(d,a,b);
		han(d-1,c,b,a);
		move(d,b,c);
		han(d-1,a,b,c);
	}
}
/*
��������
��������
1
3
12
�������
2
26
531440
*/

