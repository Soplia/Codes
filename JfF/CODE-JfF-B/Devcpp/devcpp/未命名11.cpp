//��������n�Ľ׳� n! , n�ɼ�������
#include<stdio.h>
int main()
{
	int n;
	printf("Input the n:\n");
	scanf("%d",&n);
	//��֤�Ƿ�Ϸ� 
	int sum=1;
	for(int i=1;i<=n;i++)
		sum*=i;
	printf("The result is:%d\n",sum);
	return 0;
}
