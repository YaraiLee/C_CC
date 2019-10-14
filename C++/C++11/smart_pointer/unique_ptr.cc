//g++ unique_ptr.cc  -std=c++11
//unique_ptr 是一个独享所有权的智能指针，它提供了严格意义上的所有权。它取代了C++98中的auto_ptr。用法和auto_ptr类似

#include <iostream>
#include <memory>
#include <string>
using namespace std;

unique_ptr<string> fun2(){
    return unique_ptr<string>(new string("RUS"));
}

void fun(){
    unique_ptr<string> pa(new string("CHN"));
    //unique_ptr没有use_count()方法
    unique_ptr<string> pb(new string("USA"));

    pb = move(pa);
    //p2=p1;//错误，不能直接用等于号
    if (pa == nullptr)
        

    cout << "*pb " << *pb << endl;//pb变成了“CHN”

    string* ps = pb.release();//清空当前智能指针所指的资源对象,并返回指针
    cout << "*ps " << *ps << endl;//ps变成了“CHN”
    
    if (nullptr == pb)
        cout << "pb现在为空" << endl;
    else
        cout << "*pb" << *pb << endl;

    pa.reset(ps);//重置指向另一个对象
    cout << "*pa " << *pa << endl;//pa变成了“CHN”

    pb = fun2();//接收函数的返回值可以用等于号，因为使用了移动构造函数
    cout << "*pb " << *pb << endl;//pb变成了“RUS”
}

int main()
{
    fun();
    system("pause");
}