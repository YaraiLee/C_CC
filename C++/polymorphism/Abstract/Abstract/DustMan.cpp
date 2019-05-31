#include "DustMan.h"

DustMan::DustMan(string name, string code) : Worker(name, code)
{
	cout << "DustMan(string name, string code)" << endl;
}

DustMan::~DustMan()
{
	cout << "~DustMan()" << endl;
}

void DustMan::printInfo() {
	cout << m_strName << " " << m_strCode << endl;
}