//将1—5的平方值按一定的格式存入文件，再从文件中读出输出到显示器上

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	
	if((f=fopen("mode.txt","w"))==NULL)
	{
		printf("1 Open the mode.txt file fail!\n");
		exit(0);
	}
	for(int i=1;i<=5;i++)
		fprintf(f,"%d^2=%d\n",i,i*i);
	fclose(f);
	printf("Save sucessfully!\n");
	
	if((f=fopen("mode.txt","r"))==NULL)
	{
		printf("2 Open the mode.txt file fail!\n");
		exit(0);
	}
	for(int i=1;i<=5;i++)
	{
		int a,b;
		fscanf(f,"%d^2=%d\n",&a,&b);
		printf("%d^2=%d\n",a,b);
	}
	fclose(f);
	
	return 0;
}
