#include <iostream>
#include <sstream>
using namespace std;

template <class out_type, class in_value>
out_type convert(const in_value &t)
{
    out_type result; //这里存储转换结果
    stringstream stream;
    stream << t; //向流中传值
    stream >> result; //向result中写入值
    return result;
}

int main()
{
    double d;
    string salary;
    string s ="12.56";
    d = convert<double>(s); //d等于12.56
    salary = convert<string>(9000.0); //salary等于”9000”
    cout << d << endl;
    cout << salary << endl;
    return 0;
}