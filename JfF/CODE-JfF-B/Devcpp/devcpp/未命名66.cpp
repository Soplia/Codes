//下面程序将生成 “list.dat”文件，在该文件中以“单价, 数量”格式存放
//了某商场的商品数据(商品的单价和数量分别存放在两个一维数组中)，程序将
//计算出所有商品的总金额，并将它存放在“list.dat”文件的最后一行。

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size=10;
	float price[size]={1,2,3,4,5,6,7,8,9,10};
	int num[size]={1,2,3,4,5,6,7,8,9,10};
	FILE *f;
	float sum=0;
	if((f=fopen("list.dat","w"))==NULL)
	{
		printf("Open list.dat fail!\n");
		exit(0);
	}
	for(int i=0;i<size;i++)
	{
		fprintf(f,"%.2f,%4d\n",price[i],num[i]);
		sum+=price[i]*num[i];
	}
	fwrite(&sum,sizeof(float),1,f);
	fclose(f);
	printf("Save price and num finished!\n");
	
	
	
	if((f=fopen("list.dat","r"))==NULL)
	{
		printf("Open list.dat fail!\n");
		exit(0);
	}
	float a;
	int b;
	for(int i=0;i<size;i++)
	{
		fscanf(f,"%f,%4d\n",&a,&b);
		printf("%.2f,%4d\n",a,b);
	}
	fread(&sum,sizeof(float),1,f);
	printf("%f\n",sum);
	fclose(f);
	printf("Save total price finished!\n");
	
	return 0;
}
