#include "Coordinate.h"
#include <iostream>

using namespace std;

int main(void) {
	Coordinate coor1(1, 3);
	//���Գ�Ա��������Ԫ����ʵ��һԪ������������(-)����
	cout << "���Գ�Ա��������Ԫ����ʵ��һԪ������������(-)����" << endl;
	cout << coor1.getX() << ", " << coor1.getY() << endl;
	-coor1;	//��Ա���� �൱�� coor1.operator-() ��Ԫ���� operator-(coor1)
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
	
	//���Գ�Ա��������Ԫ����ʵ�ֶ�Ԫ������Ӻ�(+)���������
	Coordinate coor2(1, 2);
	Coordinate coor3(2, 3);
	Coordinate coor4 = coor2 + coor3; //��Ա���� �൱�� coor2.operator+(coor3) ��Ԫ���� operator+(coor2, coor3)
	cout << coor4.getX() << ", " << coor4.getY() << endl;
	//������Ԫ����ʵ�ֶ�Ԫ��������(<<)���������
	cout << "������Ԫ����ʵ�ֶ�Ԫ��������(<<)���������" << endl;
	cout << coor4 << endl;

	//���Գ�Ա����ʵ�ֶ�Ԫ���������([])���������
	cout << coor4[0] << endl;
	cout << coor4[2] << endl;
	system("pause");
	return 0;
}