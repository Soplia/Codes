//��֪�����������죬�������һ������n������n��������ڼ�
#include <stdio.h>

enum weekday
{
	mon=1,
	tue=2,
	mar=3,
	tues=4,
	fir=5,
	sta=6,
	sun=7,
};

int main()
{
	int n;
	printf("input a num:\n");
	scanf("%d",&n);
	int t=n%7;
	switch(t)
	{
		case 1:printf("����һ\n");break;
		case 2:printf("���ڶ�\n");break;
		case 3:printf("������\n");break;
		case 4:printf("������\n");break;
		case 5:printf("������\n");break;
		case 6:printf("������\n");break;
		case 0:printf("������\n");break;
	}
	return 0;
}
