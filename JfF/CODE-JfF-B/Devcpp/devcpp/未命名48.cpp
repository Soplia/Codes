//ʵ���ַ�������
#include<stdio.h>

void copy(char *,char *);

int main()
{
	char a[]="I Love You!";
	char b[20];
	//ָ������ָ�� 
	void (*p)(char *,char *);
	p=copy;
	(*p)(b,a);
	
	printf("%s",b);
	return 0;
}

void copy(char *d,char *s)
{
	for(;*s!='\0';s++,d++)
		*d=*s;
	*d='\0';
}
