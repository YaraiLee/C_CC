#include "Coordinate.h"
#include <iostream>

using namespace std;

int main(void) {
	Coordinate coor1(1, 2);
	//���Գ�Ա��������Ԫ����ʵ��һԪ������������(-)����
	cout << coor1.getX() << ", " << coor1.getY() << endl;
	-(-coor1);
	cout << coor1.getX() << ", " << coor1.getY() << endl;

	system("pause");
	return 0;
}