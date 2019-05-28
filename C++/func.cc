//C++函数特性
//1.函数默认值
//2.重载
//3.inline
#include <iostream>

using namespace std;
//函数声明指定默认值，定义建议不指定默认值
//参数默认值，指定顺序要求，如果某个参数指定默认值，则该参数后边的参数必须指定默认值
void func(int a = 10, int b = 20, int c = 30);
//函数重载
void func(double a, double b);

int main(void) {
	func();
	func(100);
	func(100, 200);
	func(100, 200, 300);
	func(1.1, 2.2);

	return 0;
}

void func(int m, int n, int k) {
	cout << m << "," << n << "," << k << endl;
}

void func(double m, double n) {
	cout << m << "," << n << endl;
}
