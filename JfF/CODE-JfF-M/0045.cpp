#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String
{
 public:
	String(const char *p = NULL);
	~String(void);
	String(const String &a);
	String & operator = (const String &a);	
 private:
 	char * m_data;
};

String::String(const char *p)
{
	if (p == NULL)
	{
		m_data = (char *)malloc(sizeof(char) * 1);
		strcpy(m_data, '\0');
	}
	else
	{
		m_data = (char *)malloc(sizeof(char) * strlen(p->m_data));
		strcpy(m_data, p->m_data);
	}
}

String::~String()
{
	delete m_data [];
}

String::String(const String &a)
{
	m_data = (char *)malloc(sizeof(char) * a.m_data);
	strcpy(m_data, a.m_data);
}

String::operator =(const String &a)
{
	if (this == &a)
		return *this;
	delete m_data[];
	m_data = new char(sizeof(char) * strlen(a.m_data));
	strcpy(m_data, a.m_data);
	return *this;
}





























