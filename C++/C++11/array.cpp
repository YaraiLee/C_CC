//
// Created by liyalei on 2019/3/18.
//
#include <iostream>
#include <array>
#include <vector>

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

	std::vector<std::string> vec;
    vec.push_back("hello");
    vec.push_back("world");

    for (auto itor :vec) {
		std::cout << itor << std::endl;
	}
	
	vec.pop_back();
	std::vector<std::string>::iterator itor = vec.begin();
	for (; itor != vec.end(); itor++) {
		std::cout << *itor << std::endl;
	}
    return 0;
}
