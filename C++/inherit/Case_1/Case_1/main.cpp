#include "Soldier.h"

//��ʵ���࣬���ÿ������캯��������������Ч�ʵ�
void test1(Person p) {
	p.play();
}
//�������û���ָ�����ͣ�������ÿ������캯��������������Ч�ʸ�
void test2(Person& p) {
	p.play();
}
void test3(Person* p) {
	p->play();
}

int main(void) {
	//�ɼ̳У�ͬ������Ա����
	/*Person person;
	person.play();

	Soldier soldier;
	soldier.play("Tom", 30);
	soldier.Person::play();*/

	//isA ͨ�������ʼ�����߸�ֵ������
	//Soldier s;
	//Person p = s;
	//Person& p1 = s;
	//Person* p2 = &s;
	//p.play();	//���ø����Ա����������̳еĳ�Ա�������ظ����Ա����
	//
	//p.work();	//���󣬸��಻�ܵ��������Ա����
	
	//���಻�ܳ�ʼ�����߸�ֵ������
	//s = p; //����
	//Soldier* s1 = &p;//����

	//������,���������������virtual����������������������ִ�У��ڴ�й©
	//Person* p = new Soldier;
	//p->play();

	//delete p;
	//p = NULL;

	//�����βθ��࣬ʵ������,�����ࡢ�����á���ָ�봫��
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