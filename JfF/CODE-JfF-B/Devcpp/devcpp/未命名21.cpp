///���ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������
//һ�룬����񫣬�ֶ����һ��,�ڶ��������ֽ�ʣ�µ����ӳԵ�
//һ�룬�ֶ����һ�����Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ��
//��һ��������10���������ٳ�ʱ��ֻʣ��һ�������ˡ����һ��
//��ժ�˶��� ����
#include <stdio.h>

int rest(int);
int eat(int);

int main()
{
	for(int i=1;i<=2000;i++)
		if(eat(i)==1)
		{
			printf("%d",i);
			break;
		}
	return 0;
}

int rest(int a)
{
	return 2*(a+1);	
}
int eat(int a)
{
	for(int i=1;i<=9;i++)
	{
		a=rest(a);
		if(a<1)
			break;
	}
	return a;
}
