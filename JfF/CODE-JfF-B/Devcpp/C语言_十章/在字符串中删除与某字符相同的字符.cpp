/*
	Subject:���ַ�����ɾ����ĳ�ַ���ͬ���ַ� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:10.5
	Date_Begin:17/01/17 10:43
	Date_End:17/01/17 10:58
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 1000

char str[N];

char *delete1(char a[],char b);
char *delete2(char *a,char b);

int main()
{
	fgets(str,N,stdin);
	char b;
	b=getchar();
	puts(delete2(str,b));
	
	return 0;
}

//��ʱ�任�ռ� 
char *delete2(char *a,char b) 
{
	char *p=a;
	
	for(char *q=a;*q!='\0';) 
		if(*q==b)
			for(char *t=q;*t!='\0';t++)
				*t=*(t+1);
		else 
			q++;
	
	return p;
}

//�Կռ任ȡʱ�� 
//char *delete1(char a[],char b)
//{
//	char t[N],*q=t;
//	
//	for(char *p=a;*p!=0;p++)
//		if(*p!=b)
//		{
//			*q=*p;
//			q++;
//		}	
//	*q='\0';
//	
//	return t;
//}
/*
��������
��������
  i  miss you miss you love you   
s
�������

*/




