/*
	Subject:だんだん増（ふ）えた序列（じょれつ） 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:7.3
	Date_Begin:04/02/17 11:21
	Result:Accepted
	Date_End:04/02/17 11:36
*/
#include <stdio.h>
#define N 100

int f[N];
int array[N];

void dis(int n)
{
	for(int i=0;i<n;i++)
		printf("%-4d",f[i]);
	printf("\n");
}

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		for(int i=0;i<size;i++)
		{
			f[i]=1;
			scanf("%d",&array[i]);
		}
			
		for(int i=0;i<size;i++)	
		{
			for(int j=i-1;j>=0;j--)
				if(array[i]<=array[j])
				{
					int temp=f[j]+1;
					if(temp>f[i])
						f[i]=temp;
				}
			//dis(size);
		}
			
		int ans=f[0];
		for(int i=1;i<size;i++)
			if(f[i]>ans)
				ans=f[i];
		printf("%d\n",ans);
		
	}
	return 0;
}

/*
InputData:
8
300 207 155 300 299 170 158 65
OutputData:
6
*/



















