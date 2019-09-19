#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(){
    shared_ptr<string> country[5] =
    {
        shared_ptr<string>(new string("USA")),
        shared_ptr<string>(new string("CHN")),
        shared_ptr<string>(new string("RUS")),
        shared_ptr<string>(new string("FRA")),
        shared_ptr<string>(new string("GRB"))
    };

    shared_ptr<string> pwin;
    cout << pwin.use_count() << endl;//输出0
    pwin = country[2]; 
    /*使用shared_ptr时运行正常，因为shared_ptr采用引用计数，pwin和country[2]都指向同一块内存，
    在释放空间时因为事先要判断引用计数值的大小因此不会出现多次删除一个对象的错误。

    从名字share就可以看出了资源可以被多个指针共享，它使用计数机制来表明资源被几个指针共享。
    可以通过成员函数use_count()来查看资源的所有者个数。
    */
    cout << pwin.use_count() << endl;//输出2

    for (int i = 0; i < 5; ++i) {
        cout << *country[i]  << " -- " << country[i].use_count() << endl;//运行到[2]时崩溃，因为country[2].use_count()为2
    }
    cout << "The best is " << *pwin << endl;

    system("pause");
}