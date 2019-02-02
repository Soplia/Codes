/*
	Subject:数位分解_投机 
    Compiler:Devcpp
	Description:将数据作为字符串输入，然后进行数位分解 
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

