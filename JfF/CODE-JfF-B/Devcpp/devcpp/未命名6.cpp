//����һ����ݡ��·ݣ�������µ����������������㣩
#include<stdio.h>
int main()
{
	int year,month;
	printf("Input the year and month:\n");
	scanf("%d%d",&year,&month);
	if(year>=1869&&year<=2016&&month>=1&&month<12)
	{
		switch(month)
		{
			case 2:
				 if(year%4==0||year%100==0)
		         printf("����µ�������28��\n");
		         else
		         	 printf("����µ�������29��\n");
			break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:printf("����µ�������31��\n");break;
			case 4:
			case 6:
			case 9:
			case 11:printf("����µ�������30��\n");break;
		}
	}
	else
		printf("��ȷ�������Ƿ���ȷ!\n");
	return 0;
}
