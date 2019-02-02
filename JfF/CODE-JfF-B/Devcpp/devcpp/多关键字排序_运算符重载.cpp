/*
	Subject:��ؼ������� �ɼ������֡����� ,ʹ����������� 
    Compiler:Devcpp
	Author:JiaruiXie
	Date:04/01/17 16:02
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct student
{
	char name[101];
	int age;
	float score;
	//ע������ط�ʹ�õ������ã��������ص���һ��û��ʹ��this���������� 
	bool operator < (const struct student &x )const
	{
		int temp=strcmp(name,x.name);
		if(score!=x.score)
			return score<x.score;
		else if(temp!=0)
			return temp<0;
		return age<x.age;
	}
}Stu;

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
		sort(p,p+size);
		for(int i=0;i<size;i++)
			cout<<p[i].name<<" "<<p[i].age<<" "<<p[i].score<<endl;
		cout<<endl;
	}
}

