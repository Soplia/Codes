//�Ӽ�������һ���ַ������롮#��ʱ���������ַ����Ĵ�д��ĸ
//ת��ΪСд��ĸ����������ַ�ֱ�����

//�������
 
#include<stdio.h>
#include<string.h>

bool isChar(char);
void convert(char *);
void myStrupr(char *);
int main()
{
	//printf("%c",'a'-32);
	char a[]="I loVe You,Do you konW!";
	convert(a);
	return 0;
}

bool isChar(char a)
{
	return 'a'<=a&&a<='z'||'A'<=a&&a<='Z'?true:false;
}

void convert(char *a)
{
	puts(a);
	for(int i=0;i<strlen(a);i++)
		if(isChar(a[i]))
			myStrupr(&a[i]);
			
	puts(a);
}

void myStrupr(char *a)
{
	*a-=32;
}
