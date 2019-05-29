#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s1 = "hello";
	string s2 = "world!";
	string s3 = s1 + ' ' + s2;

	cout << s3 << endl;

//	string s4 = " hi" + "ok!" + s3; //错误
	string s4 = s3 + " hi" + "ok!";
	cout << s4 << endl;
	return 0;
}
