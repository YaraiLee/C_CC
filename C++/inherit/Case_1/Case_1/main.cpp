#include "Soldier.h"

int main(void) {
	//�ɼ̳У�ͬ������Ա����
	Person person;
	person.play();

	Soldier soldier;
	soldier.play("Tom", 30);
	soldier.Person::play();


	system("pause");
	return 0;
}