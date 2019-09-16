#include <iostream>

using namespace std;

int main(void)
{
	const int a = 10;
	const int *pInt = &a;
	cout << *pInt << endl;
	// a = 20;
	// *pInt = 20;
	// cout << *pInt << endl;
	int b = 11;
	pInt = &b;
	cout << *pInt << endl;
	b = 12;	//通过修改b从而修改*pInt
	cout << *pInt << endl;
	//a只读，p可读可写,权力放大，错误
//	int *p = &a;

	return 0;
}
