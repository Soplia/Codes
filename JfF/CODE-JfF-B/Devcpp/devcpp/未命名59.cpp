//�Ӽ�������һ���ַ���д�뵽�ı��ļ���string.txt���С�

#include<stdlib.h>
#include<stdio.h>

int main()
{
	char a[100];
	printf("Input a string:\n");
	gets(a);
	FILE *f;
	if((f=fopen("string.txt","w"))==NULL)
	{
		printf("Open the file fail!\n");
		exit(0);
	}
	else
	{
		for(int i=0;;i++)
		{
			if(a[i]!='\0')
				fputc(a[i],f);
			else
				break;
		}
		fclose(f);
	}
	
	return 0;
}
