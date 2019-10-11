#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"


MyString::MyString(const char* ptrData)
{
	cout << "MyString(const char* ptrData)" << endl;
	if (NULL == ptrData) {
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else {
		int len = strlen(ptrData);
		m_data = new char[len + 1];
		strcpy(m_data, ptrData);
		m_data[len] = '\0';
	}
}

MyString::~MyString(void)
{
	cout << "~MyString()" << endl;
	delete[]m_data;
}

MyString::MyString(const MyString& other) {
	cout << "MyString(const MyString& other)" << endl;

	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);
	m_data[len] = '\0';
}

MyString& MyString::operator=(const MyString& other) {
	cout << "operator=(const MyString& other)" << endl;
	if (&other == this) {
		return *this;
	}
	delete []m_data;
	int len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);
	m_data[len] = '\0';
	return *this;
}

ostream& operator<<(ostream& out, const MyString& str) {
	out << str.m_data;
	return out;
}
