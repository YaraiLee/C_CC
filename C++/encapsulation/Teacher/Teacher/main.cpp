#include "Teacher.h"
#include <iostream>

using namespace std;

int main(void)
{
	Teacher t;
	cout << t.getName() << " " << t.getAge() << endl;

	Teacher *t1 = new Teacher("Lee", 29);

	cout << t1->getName() << " " << t1->getAge() << endl;

	Teacher t2(*t1);
	cout << t2.getName() << " " << t2.getAge() << endl;

	delete t1;
	t1 = NULL;

	//unsigned int *p = (unsigned int *)0x00000001;
	//p = p + 5;
	//cout << p << endl;

	//cout << sizeof(unsigned int) << endl;

	//cout << sizeof(long) << endl;
	//cout << sizeof(void *) << endl;
	system("pause");
	return 0;
}