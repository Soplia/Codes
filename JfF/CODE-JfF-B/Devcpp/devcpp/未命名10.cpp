//���һ���質�����ļƷֳ���, ��10��ר�Ҹ����ִ��, 
        //���ֵ����ճɼ�Ϊȥ��һ����߷ֺ�һ����ͷֵ�ƽ����
#include<stdio.h>
int main()
{
	int max=-1111,min=9999;
	double sum=0;
	printf("������ѧ���ɼ�:\n");
	int i;
	for(int j=0;j<10;j++)
	{
		scanf("%d",&i);
		sum+=i;
		if(i>max)
	 max=i;
	 else if(i<min)
	 min=i;
	}
	sum=sum-min-max;
	printf("%.2f",sum/8);
	return 0;
	
}

