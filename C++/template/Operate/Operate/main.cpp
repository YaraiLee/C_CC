#include "Coordinate.h"
#include <iostream>

using namespace std;

int main(void) {
	Coordinate coor1(1, 3);
	//���Գ�Ա��������Ԫ����ʵ��һԪ������������(-)����
	cout << "���Գ�Ա��������Ԫ����ʵ��һԪ������������(-)����" << endl;
	cout << coor1.getX() << ", " << coor1.getY() << endl;
	-(-coor1);
	cout << coor1.getX() << ", " << coor1.getY() << endl;

	//���Գ�Ա��������Ԫ����ʵ��һԪ�����ǰ�����������(++)����
	cout << "���Գ�Ա��������Ԫ����ʵ��һԪ�����ǰ�����������(++)����" << endl;
	++coor1;
	cout << coor1.getX() << ", " << coor1.getY() << endl;
	
	//���Գ�Ա����ʵ��һԪ������������������(++)����
	cout << "���Գ�Ա��������Ԫ����ʵ��һԪ������������������(++)����" << endl;
	cout << coor1++.getX() << ", ";	//���д�ӡ����	cout << coor1++.getX() << ", " << coor1++.getY() << endl;��������ͬ�������Ǵ�������˳��ִ��
	cout << coor1++.getY() << endl;

	cout << coor1.getX() << ", " << coor1.getY() << endl;

	system("pause");
	return 0;
}