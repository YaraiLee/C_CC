#include "Soldier.h"

int main(void) {
	//可继承，同名，成员隐藏
	Person person;
	person.play();

	Soldier soldier;
	soldier.play("Tom", 30);
	soldier.Person::play();


	system("pause");
	return 0;
}