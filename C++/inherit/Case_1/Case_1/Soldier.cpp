#include "Soldier.h"

Soldier::Soldier(string name, int age) {
	cout << "Soldier(string name, int age)" << endl;
	m_strName = name;
	m_iAge = age;
}

Soldier::~Soldier() {
	cout << "~Soldier()" << endl;
}
//���ඨ�常��ͬ����������ʹ������ͬ�������ظ���ͬ������
bool Soldier::play(string name, int age) {
	cout << "Soldier::play()" << endl;
	m_strName = name;
	m_iAge = age;
	cout << m_strName << " " << m_iAge << endl;
	return true;
}

void Soldier::work() {
	cout << "Soldier::work()" << endl;
}