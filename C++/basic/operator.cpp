//
// Created by liyalei on 2019/2/8.
//
#include <iostream>

using namespace std;

class Box {
public:
    double getVolume() {
        return length * width * height;
    }

    void setLength(int length) {
        this->length = length;
    }

    void setWidth(int width) {
        this->width = width;
    }

    void setHeight(int height) {
        this->height = height;
    }

    Box operator+(const Box &b) {
        Box box;
        box.height = this->height + b.height;
        box.width = this->width + b.width;
        box.length = this->length + b.length;
        return box;
    }
    //后++
    Box operator++(int n) {
        Box box = *this;
        this->height += 1;
        this->width += 1;
        this->length += 1;
        return box;
    }
    //前++
    Box operator++() {
        this->length += 1;
        this->width += 1;
        this->height += 1;
        return *this;
    }

private:
    int length;
    int width;
    int height;
};

int main() {
    Box box1, box2, box3;

    box1.setHeight(1);
    box1.setLength(2);
    box1.setWidth(3);
    cout << box1.getVolume() << endl;
    box1++;
    cout << box1.getVolume() << endl;
    ++box1;
    cout << box1.getVolume() << endl;
    return 0;
}


