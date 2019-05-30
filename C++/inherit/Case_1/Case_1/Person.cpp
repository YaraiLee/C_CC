#include "Person.h"

Person::Person(string name, int age) {
	m_strName = name;
	m_iAge = age;
	cout << "Person(string name)" << endl;
}

Person::~Person() {
	cout << "~Person(" << endl;
}

void Person::play() {
	cout << "Person::play()" << endl;
	cout << m_strName  << " " << m_iAge << endl;
}