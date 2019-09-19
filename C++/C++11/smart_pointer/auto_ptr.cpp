//g++ auto_ptr.cpp -lstdc++

//auto_ptr这是C++98标准下的智能指针，现在常常已经被C++标准的其他智能指针取代。
//它的缺点是在转移所有权后会使运行期不安全。C++11新标准，用unique_ptr来代替auto_ptr原有功能
#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(){
    auto_ptr<string> country[5] =
    {
        auto_ptr<string>(new string("USA")),
        auto_ptr<string>(new string("CHN")),
        auto_ptr<string>(new string("RUS")),
        auto_ptr<string>(new string("FRA")),
        auto_ptr<string>(new string("GRB"))
    };

    auto_ptr<string> pwin;
    pwin = country[2]; //将所有权从country[2]转让给pwin，此时country[2]不再引用该字符串从而变成空指针，在运行到循环时就会崩溃

    for (int i = 0; i < 5; ++i)
        cout << *country[i] << endl;//运行到[2]时崩溃，因为country[2]为空
    cout << " The best is " << *pwin << endl;

    system("pause");
    return 0;
}