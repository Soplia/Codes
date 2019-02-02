/*
	Subject:��ؼ������� �ɼ������֡����� ,ʹ�ñȽϺ��� 
    Compiler:Devcpp
	Author:JiaruiXie
	Date:04/01/17 15:18
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct student
{
	//��Ϊstring����һ�ж���Ϊһͳһ�������ˣ����Գ��ִ��� 
	//string name;
	char name[101];
	int age;
	float score;
}Stu;

//������������˱ȽϹ��� 
bool cmp(Stu x,Stu y)
{
	int temp=strcmp(x.name,y.name);
	if(x.score!=y.score)
		return x.score<y.score;
	else if(temp!=0)
		return temp<0;
	else
		return x.age<y.age;
}

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		Stu *p=(Stu *)malloc(size*sizeof(Stu));
		for(int i=0;i<size;i++)
		{
			scanf("%s",p[i].name);
			cin>>p[i].age;
			cin>>p[i].score;
		}
		
	
		sort(p,p+size,cmp);
		
		
		
		
		
		for(int i=0;i<size;i++)
			cout<<p[i].name<<" "<<p[i].age<<" "<<p[i].score<<endl;
		cout<<endl;
	}
}
