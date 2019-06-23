#include "MyString.h"

using namespace std;

int main(void) {
	MyString str1;
	MyString str2("Hello MyString!");
	MyString str3 = str2;

	MyString* ptrStr = new MyString("asdfasdfasf");

	cout << *ptrStr << endl;
	cout << str2 << endl;

	delete ptrStr;
	ptrStr = NULL;

	system("pause");
	return 0;

}