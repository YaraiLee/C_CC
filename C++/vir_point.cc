#include <iostream>
using namespace std;

class A
{
  public:
    int a;
    virtual void myfun() {}
};

class B : public A
{
  public:
    int b;
};

int main()
{
    B obj_b;
    obj_b.a = 1;
    obj_b.b = 2;
    A *p = &obj_b;
    cout << p << endl;  //虚函数表指针
    cout << &(p->a) << endl;
    cout << p->a << '\t' << *(&(p->a) + 1) << endl; //*(&(p->a) + 1) --> obj_b.b，父类指针不能直接获取子类的变量，指针的访问范围由的类型决定
}