//��ĳ����Ӣ��ɼ���ƽ����, �ð�ѧ��������ÿ��ѧ���ĳɼ��ɼ�������
#include <stdio.h>
int main()
{
	int num;
	printf("������ѧ����������\n");
	scanf("%d",&num);
	int sum=0;
	for(int i=0;i<num;i++)
	{
	 		int j;
	scanf("%d",&j);
		sum+=j;
	}
	return 0;
}
