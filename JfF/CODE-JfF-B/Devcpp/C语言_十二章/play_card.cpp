#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <stdlib.h>
#define N 52

typedef struct card
{
	char suit[12];
	char num[6];
}Card;

Card myCard[N];
char flower[4][10]={"Spades","Hearts","Clubs","Diamondas"};
char dia[13][6]={"A","2","3","4","5","6","7","8","9","10","Jack","Queue","King"};

void sendCard()
{
	for(int i=0;i<52;i++)
	{
		strcpy(myCard[i].suit,flower[i/13]);
		strcpy(myCard[i].num,dia[i%13]);
	}
} 

void change()
{
	for(int i=0;i<N;i++)
	{
		Card temp;
		int j=rand()%52;
		//不知道这样赋值是否可以。 
		temp=myCard[i];
		myCard[i]=myCard[j];
		myCard[j]=temp;
	}	
}

//这个输出写的相当不错 
void output()
{
	for(int i=0;i<52;i++)
		printf("%9s%9s%c",myCard[i].suit,myCard[i].num,i&1==0?'\n':'\t');
}


int main()
{
	srand(time(NULL));
	sendCard();
	output();
	printf("\n");
	change();
	output();
	return 0;
}
