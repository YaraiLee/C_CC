#include "Person.h"

Person::Person(string name) {
	m_strName = name;
	cout << "Person(string name)" << endl;
}

Person::~Person() {
	cout << "~Person()" << endl;
}