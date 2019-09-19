#include <iostream>
#include <memory>
#include <string>
using namespace std;

class B;    //先声明，后定义
class A
{
public:
    shared_ptr<B> pb_;
    ~A()
    {
        cout << "A delete\n";
    }
};
class B
{
public:
    shared_ptr<A> pa_;
    ~B()
    {
        cout << "B delete\n";
    }
};

void fun(){
    shared_ptr<B> pb(new B());
    cout << "pb.use_count " << pb.use_count() << endl;//1
    shared_ptr<A> pa(new A());
    cout << "pa.use_count " << pa.use_count() << endl;//1

    pb->pa_ = pa;
    cout << "pb.use_count " << pb.use_count() << endl;//1
    cout << "pa.use_count " << pa.use_count() << endl;//2
    pa->pb_ = pb;
    cout << "pb.use_count " << pb.use_count() << endl;//2：由于share_ptr是共享资源，所以pb所指向的资源的引用计数也会加1
    cout << "pa.use_count " << pa.use_count() << endl;//2
}//程序结束时，没有调用A和B的析构函数,A中的pb_或者B中的pa_定义为weak_ptr即可

int main()
{
    fun();
    system("pause");
}