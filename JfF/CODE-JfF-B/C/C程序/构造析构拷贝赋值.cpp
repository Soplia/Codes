#include <iostream>
#include <cstring>
using namespace std;

class String
{
 public:
 	String(char *str=NULL);
 	String(const String &other);
 	String& operator =(const String &other);
 	~String(void);
 private:
 	char *m_Data;
};

String::String(char *str)
{
	if(str==NULL)
	{
		m_Data=new char[1] ;
		*m_Data='\0';
	} 
	else
	{
		m_Data=new char[strlen(str)+1];
		strcpy(m_Data,str);
	}
}
String::String(const String &other)
{	
	m_Data=new char[strlen(other.m_Data)+1];
	strcpy(m_Data,other.m_Data);
}

String& String::operator =(const String &other)
{
	if(this==&other)
		return *this;
	delete [] m_Data;
	m_Data=new char[strlen(other.m_Data)+1];
	strcpy(m_Data,other.m_Data);
	return *this;
}
String::~String()
{
	delete [] m_Data;
}

int main()
{
	return 0;
}



























