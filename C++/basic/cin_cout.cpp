#include<iostream>
#include <stdlib.h>

using namespace std;
//输入一个数按8进制、10进制、16进制输出
//bool true
int main(void) 
{
	cout << "请输入一个整数：";
	int x = 0;
	cin >> x;
	cout << oct << x << endl;
	cout << dec << x << endl;
	cout << hex << x << endl;

	cout << "请输入一个布尔值（0、1）：" << endl;
	bool y = true;
	cin >> y;
	cout << "y=" << y << endl;
	cout << boolalpha<< y << endl;
	system("pause");
	return 0;
}
