//hanoi
#include<stdio.h>

void move(int,char,char);
void hanoi(int,char,char,char);

int main()
{
	int num;
	printf("请输入碟子的数量:\n");
	scanf("%d",&num);
	hanoi(num,'A','B','C');
	return 0; 
}

void move(int k,char a,char b)
{
	printf("将第 %d 个盘子从第 %c 个柱子上移动到第 %c 个柱子上\n",k,a,b);
}

void hanoi(int k,char a,char b,char c)
{
	if(k==1)
		move(k,a,c);
	else
	{
		hanoi(k-1,a,c,b);
		move(k,a,c);
		hanoi(k-1,b,a,c);
	}
}
