#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
int data[MAXNUM];
int num;   //��¼�������ݵĸ���
int countOfBinSearch=1;//���ȫ�ֱ������ڼ�¼���ҵĴ���
						//���ܰ��������ɾֲ�����Ϊ����������Ļ�ÿ�εݹ鶼�����±���ֵ�ġ� 
int search_seq(int a)   //˳����ң�����Ԫ�أ����رȽϴ���
{
	int count=1;
	for(int i=0;i<num;i++)
	{
		if(a==data[i])
			break;
		else
			count++;	
	}
	return count;
}
int search_bin(int a,int start,int end)   //�۰���ң�����Ԫ�أ����رȽϴ���
{
	int mid=(start+end)/2;
	if(data[mid]==a)
		return countOfBinSearch;
	else
	{
		countOfBinSearch++;
		if(a<data[mid])
			search_bin(a,0,mid-1);
		else if(a>data[mid])
			search_bin(a,mid+1,end);
	}	
}
int main()
{
	int aim;
	int count1,count2;
	double average1,average2;
	printf("���������ݵĸ���:\n");
	scanf("%d",&num);
	if (num>MAXNUM || num<1) 
	{
		printf("input error");
		return 0;
	}
    printf("�����������ݵļ���,�Կո���:\n");
	for(int i=0;i<num;i++)
		scanf("%d",&data[i]);
	printf("��������������:\n");
	scanf("%d",&aim);
	count1=search_seq(aim);
	printf("˳����ҵĴ�����:%d\n",count1);
	count2=search_bin(aim,0,num-1); 
	printf("�۰���ҵĴ�����:%d\n",count2);
	average1=(float)count1/num;
	average2=(float)count2/num; 
	printf("˳����ҳɹ�ƽ���Ƚϴ���Ϊ%.2lf\n",average1);
	printf("�۰���ҳɹ�ƽ���Ƚϴ���Ϊ%.2lf\n",average2);
	return 0;
}

















