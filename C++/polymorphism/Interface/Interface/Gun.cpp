#include "Gun.h"

Gun::Gun()
{
	m_pInt = new int;
	cout << "Gun()" << endl;
}

Gun::~Gun()
{
	delete m_pInt;
	m_pInt = NULL;
	cout << "~Gun()" << endl;
}

void Gun::aim() {
	cout << "Gun::aim()" << endl;
}

void Gun::reload() {
	cout << "Gun::reload()" << endl;
}