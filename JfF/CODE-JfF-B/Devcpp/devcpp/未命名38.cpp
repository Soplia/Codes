//hanoi
#include<stdio.h>

void move(int,char,char);
void hanoi(int,char,char,char);

int main()
{
	int num;
	printf("��������ӵ�����:\n");
	scanf("%d",&num);
	hanoi(num,'A','B','C');
	return 0; 
}

void move(int k,char a,char b)
{
	printf("���� %d �����Ӵӵ� %c ���������ƶ����� %c ��������\n",k,a,b);
}

void hanoi(int k,char a,char b,char c)
{
	if(k==1)
		move(k,a,c);
	else
	{
		hanoi(k-1,a,c,b);
		move(k,a,c);
		hanoi(k-1,b,a,c);
	}
}
