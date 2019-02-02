#include <stdio.h>
#include <stdlib.h>

void quick_sort(int s[], int l, int r)  
{  
    int i, j, x;  
    if (l < r)  
    {  
        i = l;  
        j = r;  
        x = s[i];  
        while (i < j)  
        {  
            while(i < j && s[j] > x)   
                j--; /* ���������ҵ�һ��С��x���� */  
            if(i < j)   
                s[i++] = s[j];  
      
  
            while(i < j && s[i] < x)   
                i++; /* ���������ҵ�һ������x���� */  
            if(i < j)   
                s[j--] = s[i];  
  
        }  
        s[i] = x;  
        quick_sort(s, l, i-1); /* �ݹ���� */  
        quick_sort(s, i+1, r);  
    }  
}  

int cmp(const void *a ,const void *b)
{
	return (int *)a-(int *)b;
}

int main()
{
	int temp;
	const int sizeOfArray=10000000;
	int arr[sizeOfArray]={};
	quick_sort(arr,0,sizeOfArray-1);
	
	FILE *fp;
	fp=fopen("2.txt","w");
	if(fp!=NULL)
	{
		for(int i=0;i<sizeOfArray;i++)
		{
			fprintf(fp,"%d,",arr[i]);
		}
	}
	fclose(fp);
	printf("Create File Success!\n");
	return 0;
}
