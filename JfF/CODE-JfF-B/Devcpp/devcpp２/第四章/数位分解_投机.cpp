/*
	Subject:��λ�ֽ�_Ͷ�� 
    Compiler:Devcpp
	Description:��������Ϊ�ַ������룬Ȼ�������λ�ֽ� 
	Author:JiaruiXie
	Id:4-2-1
	Date_Begin:11/01/17 19:23
	Date_End:11/01/17 19:27
*/
#include <stdio.h>

int main()
{
	char a[11],b[11];
	int ans=0;
	while(scanf("%s%s",a,b)!=EOF)
	{
		for(int i=0;a[i]!=0;i++)
			for(int j=0;b[j]!=0;j++)
				ans+=(a[i]-'0')*(b[j]-'0');
		printf("%d\n",ans);
	}
	return 0;
}

