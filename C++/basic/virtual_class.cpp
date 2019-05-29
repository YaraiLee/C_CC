#include <iostream>

using namespace std;

//基类
class D {
public:
    D() { cout << "D()" << endl; }

    D(string strInfo) {
        cout << strInfo << endl;
    }

    ~D() { cout << "~D()" << endl; }

protected:
    int d;
};

class B : virtual public D {
public:
    B() { cout << "B()" << endl; }

    ~B() { cout << "~B()" << endl; }

protected:
    int b;
};

class A : virtual public D {
public:
    A() { cout << "A()" << endl; }

    ~A() { cout << "~A()" << endl; }

protected:
    int a;
};

class C : public B, public A {
public:
    C() { cout << "C()" << endl; }

    ~C() { cout << "~C()" << endl; }

protected:
    int c;
};

int main() {

    cout << "Hello World!" << endl;
    C c;   //D, B, A ,C
    cout << "int:" << sizeof(int) << endl;
    cout << "D:" << sizeof(D) << endl;
    cout << "B:" << sizeof(B) << endl;
    cout << "A:" << sizeof(A) << endl;
    cout << "C:" << sizeof(c) << endl;

    char test[] = "hello!\n";
    D *pD = new D(test);
    cout << sizeof(pD) << endl;
    delete pD;
    return 0;
}
