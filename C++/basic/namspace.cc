//namespace demo
#include <iostream>
using namespace std;

namespace A 
{
	int x = 1;
	void func() {
		cout << "A" << endl;
	}
}

namespace B {
	int x = 2;
	void func() {
		cout << "B" << endl;
	}

	void func_1()
	{
		cout << "func_1" << endl;
	}
}

using namespace B;

int main(int argc, char* argv[])
{
	cout << A::x << endl;
	A::func();
	func();
	func_1();
	return 0;
}
