#pragma once
#include <iostream>
using namespace std;
//��д��String�Ĺ��캯�����������캯�������������͸�ֵ����
class MyString
{
	friend ostream& operator<<(ostream& out, const MyString& str);
public:
	MyString(const char* ptrData = NULL);
	~MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
private:
	char* m_data;
};
