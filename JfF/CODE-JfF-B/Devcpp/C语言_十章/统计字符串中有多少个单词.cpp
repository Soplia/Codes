/*
	Subject:ͳ���ַ������ж��ٸ����� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:10.4
	Date_Begin:17/01/17 10:08
	Date_End:
*/
#include <stdio.h>
#include <ctype.h>
#define N 1000

char str[N];

int main()
{
	fgets(str,N,stdin);
	bool flag=true;
	int ans=0;
	
	for(char *p=str;*p!=0;p++)
		if(!isalpha(*p))
			flag=true;
		else if(flag&&isalpha(*p))
		{
			flag=false;
			ans++;
		}
		
	printf("%d\n",ans);
	return 0;
}
//����������� 
//int main()
//{
//	fgets(str,N,stdin);
//	int ans=0;
//	char *p=str;
//	
//	do
//	{
//		while(!isalpha(*p))	
//		{
//			
//			if(*p=='\0')
//				break;
//			p++;	
//		}
//		if(isalpha(*p))
//			ans++;
//		while(!isspace(*p))
//		{
//			if(*p=='\0')
//				break;
//			p++;	
//		}
//	}while(*p!='\0');
//	
//	printf("%d\n",ans);
//	return 0;
//}
/*
��������
��������
   i   miss   you     
�������
3
*/

