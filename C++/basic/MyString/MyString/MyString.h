#pragma once
#include <iostream>
using namespace std;
//编写类String的构造函数、拷贝构造函数、析构函数和赋值函数
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
