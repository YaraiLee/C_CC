#include "Soldier.h"

//传实体类，调用拷贝构造函数和析构函数，效率低
void test1(Person p) {
	p.play();
}
//传类引用或者指针类型，不会调用拷贝构造函数和析构函数，效率高
void test2(Person& p) {
	p.play();
}
void test3(Person* p) {
	p->play();
}

int main(void) {
	//可继承，同名，成员隐藏
	/*Person person;
	person.play();

	Soldier soldier;
	soldier.play("Tom", 30);
	soldier.Person::play();*/

	//isA 通过子类初始化或者赋值给父类
	//Soldier s;
	//Person p = s;
	//Person& p1 = s;
	//Person* p2 = &s;
	//p.play();	//调用父类成员函数，子类继承的成员变量隐藏父类成员变量
	//
	//p.work();	//错误，父类不能调用子类成员函数
	
	//父类不能初始化或者赋值给子类
	//s = p; //错误
	//Soldier* s1 = &p;//错误

	//虚析构,父类析构函数添加virtual，否则子类析构函数不会执行，内存泄漏
	//Person* p = new Soldier;
	//p->play();

	//delete p;
	//p = NULL;

	//函数形参父类，实参子类,区别类、类引用、类指针传参
	//Person p;
	Soldier s;
	test1(s);
	//test1(p);
	//test2(s);
	//test2(p);
	//test3(&s);
	//test3(&p);

	system("pause");
	return 0;
}