#include <iostream>

using namespace std;
typedef struct {
	int x;
	int y;
}Coor;

void func(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	//数值引用
	int a = 10;
	int &b = a;
	a = 20;
	cout << b << endl;

	b = 30;
	cout << a << endl;
	//结构体引用
	Coor c;
	Coor &c1 = c;
	c.x = 1;
	c.y = 2;
	cout << c1.x << " " << c1.y << endl;

	c1.x = 3;
	c1.y = 4;
	cout << c.x << " " << c.y << endl;
	//指针引用
	int *p = &a;
	int *&q = p;
	cout << "*q=" << *q << endl;
	*p = 11;
	cout << "*q=" << *q << endl;
	cout << "a=" << a << endl;
	//引用做函数参数
	int x = 100, y = 200;
	cout << "swap before: x=" << x << " y=" << y << endl;
	func(x, y);
	cout << "swap after: x=" << x << " y=" << y << endl;
	return 0;
}
