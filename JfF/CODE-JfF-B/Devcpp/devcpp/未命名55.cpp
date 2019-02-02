#include <stdio.h>

typedef union st
{
	int numOfClass;
	char name[10];
}ST;

typedef struct st1
{
	int type;
	ST room;
}S;

int main()
{
	char next='y';
	S myS[100];
	int i=0;
	while(next=='y'||next=='Y')
	{
		printf("Input the type:\n");
		scanf("%d",&myS[i].type);
		printf("Inupt the room:\n");
		switch(myS[i].type)
		{
			case 0:scanf("%d",&(myS[i].room.numOfClass));break;
			case 1:scanf("%s",myS[i].room.name);break;
		};
		getchar();
		printf("Continue?\n");
		scanf("%c",&next);
	}
	for(int j=0;j<i;j++)
	{
		printf("%-3d",myS[j].type);
		switch(myS[j].type)
		{
			case 0:printf("%d",myS[i].room.numOfClass);break;
			case 1:scanf("%s",myS[i].room.name);break;
		};
	}
	return 0;
}




