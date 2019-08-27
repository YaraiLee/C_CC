//
// Created by liyalei on 2019/8/27.
//
#include <iostream>
#include <stdlib.h>
#include <time.h>

static std::string RQSTID(int n=20) {
    static char CHARS[] = "abcdefghijklmnopqrstuvwxwz1234567890";
    std::string uuid(n, '0');
    for(size_t i=0; i<uuid.size(); i++)
        uuid[i] = CHARS[rand()%(sizeof(CHARS)-1)];
    return uuid;
}

int main() {
    srand(time(NULL));
    for (int i = 0 ; i < 10; i++) {
        std::cout << RQSTID() << std::endl;
    }
    return 0;
}

