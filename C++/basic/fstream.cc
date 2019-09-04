#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout("./test.txt");   //ofstream构造函数调用open函数，并且创建或清空文件
    if (!fout.is_open()) {
        std::cerr << "open error!" << std::endl;
        return -1;
    }

    for (int i = 0; i < 3; i++) {
        fout << "index " << i << std::endl;
    }

    fout.close();
    return 0;
}