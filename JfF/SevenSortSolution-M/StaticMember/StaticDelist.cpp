#include <iostream>
#include <stdio.h>
using namespace std;

class Delist
{
public:
	Delist(string name);
	~Delist();
	static void DisDelist();
private:
	static Delist * head;
	Delist * next;
	Delist * pre;
	string name;
};

Delist::Delist(string name)
{
	this->name = name;
	this->next = head;
	this->pre = NULL;
	if (NULL != head)
		head->pre = this;
	head = this;
}
Delist::~Delist()
{
	if (this == head)
		head = head->next;
	else
	{
		this->next->pre = this->pre;
		this->pre->next = this->next;
	}
}
void Delist::DisDelist()
{
	for (Delist * temp = head; NULL != temp; temp = temp->next)
		printf("%s\n", temp->name.c_str());
		//cout << temp->name << endl;
}

Delist * Delist::head = NULL;

int main()
{
	Delist a("a");
	Delist b("b");
	Delist c("c");
	Delist d("d");
	d.DisDelist();
	system("pause");
	return 0;
}