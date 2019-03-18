//
// Created by liyalei on 2019/3/18.
//
#include <iostream>
#include <array>

int main(int argc, char** argv) {
    std::array<int, 4> arrayDemo = { 1,2,3,4 };
    std::cout << "arrayDemo:" << std::endl;
    for (auto itor : arrayDemo)
    {
        std::cout << itor << std::endl;
    }
    int arrayDemoSize = sizeof(arrayDemo);
    std::cout << "arrayDemo size:" << arrayDemoSize << std::endl;

    int a[] = {1,2,4,5,6};
    std::cout << "a size=" << sizeof(a) << std::endl;
    std::cout << "ele size=" << sizeof(a)/ sizeof(a[0]) << std::endl;
    return 0;
}
