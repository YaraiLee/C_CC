#include <iostream>
#include <string>
using namespace std;

void fun(){
    shared_ptr<string> pa(new string("CHN"));
    shared_ptr<string> pb(new string("USA"));
    cout << "*pa " << *pa << endl;//CHN
    cout << "pa.use_count " << pa.use_count() << endl;//1
    cout << "*pb " << *pb << endl;//USA
    cout << "pb.use_count " << pb.use_count() << endl;//1

    pa = pb;
    cout << *pa << endl;//USA
    cout << "pa.use_count " << pa.use_count() << endl;//2：pa和pb指向同一个资源USA了，该资源的计数为2，所以pb、pb都输出2
    cout << "pb.use_count " << pb.use_count() << endl;//2

    pa.reset();
    pb.reset();
    cout << "pa.use_count " << pa.use_count() << endl;//0
    cout << "pb.use_count " << pb.use_count() << endl;//0
}

int main()
{
    fun();
    system("pause");
    return 0;
}