#include <iostream>
#include <thread>

class MyFunctor
{
public:
    void operator()() {
        std::cout << "functor\n";
    }
};

int main()
{
    // MyFunctor fnctor;
    // std::thread t(fnctor);
    //同上2行，不能是std::thread t(MyFunctor())
    std::thread t((MyFunctor()));
    std::cout << "main thread\n";
    t.join();
    return 0;
}