#include <stdio.h>
#include <string.h>

typedef struct ca
{
	char name[20];
	int ret;
	void init(char a[])
	{
		strncpy(name,a,20);
		ret=0;
	}
}C;

C myC[3]={"zhang",0,"li",0,"wang",0};

int main()
{
	int rest=0;
	char n[20];
	
	for(int i=0;i<10;i++)
	{
		//fgets(n,sizeof(char )*20,stdin);
		//ʹ��scanf�����ַ���ʱ�����ж���Ŀո�
		//����ʹ��fgets��getʱ�����ж���Ŀո� 
		scanf("%s",n);
		//ʹ�����strlwr���д�Сд��ĸת�� 
		strlwr(n);
		printf("*%s*\n",n);
		if(strcmp(n,"zhang")==0)
			myC[0].ret++;
		else if(strcmp(n,"li")==0)
			myC[1].ret++;
		else if(strcmp(n,"wang")==0)
			myC[2].ret++;
		else
			rest++;
	}
	
	for(int i=0;i<3;i++)
		printf("%s:%d\n",myC[i].name,myC[i].ret);
	printf("%d\n",rest);
	
	return 0;
}

/*
��������
��������
li
li
Li
wang
zhang
Wang
Zhang
wang
li 
lii 
�������
li:4
zhang:2
wang:3
1
*/


























