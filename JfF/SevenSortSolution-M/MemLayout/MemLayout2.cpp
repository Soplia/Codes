#include <stdio.h>
#include <stdlib.h>

void fun(int i)
{
	int j = i;
	static int s_i = 1, s_j;
	printf("�Ӻ����в������ݵ�ַ:%p = %d\n", &i, i);
	printf("�Ӻ�����ջ���ݵ�ַ���ѳ�ʼ����:%p = %d\n", &j, j);
	printf("�Ӻ����о�̬���ݵ�ַ���ѳ�ʼ����:%p = %d\n", &s_i, s_i);
	printf("�Ӻ����о�̬���ݵ�ַ��δ��ʼ����:%p = %d\n", &s_j, s_j);
}

int main()
{
	int i = 4;
	static int s_i = 1, s_j;
	printf("��������ջ���ݵ�ַ���ѳ�ʼ����:%p = %d\n", &i, i);

	printf("�������о�̬���ݵ�ַ����ʼ����:%p = %d\n", &s_i, s_i);
	printf("�������о�̬���ݵ�ַ��δ��ʼ����:%p = %d\n", &s_j, s_j);
	fun(i);
	system("pause");
	return 0;
}