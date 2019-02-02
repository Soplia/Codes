#include <stdio.h>

void print(char *arr[],int len);

int main()
{
	char *pArray[]= {"i","misssssss","you"};
	//num值得计算有问题 
	printf("sizeof(pArray)=%d,sizeof(int *)=%d\n",sizeof(pArray),sizeof(int* ));
	int num= sizeof(pArray)/sizeof(char *);
	printf("num=%d\n",num);
	print(pArray,num);
	return 0;
} 

void print(char *arr[],int len)
{
	for(int i=0;i<len;i++)
		printf("%s ",arr[i]);
	printf("\n");
}
