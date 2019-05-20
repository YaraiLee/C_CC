#include <iostream>

using namespace std;

template <typename T>
T t_max(const T a, const T b) {
	return a > b ? a: b;
}

template <typename T, class U>
void display(const T t, const U u) {

	cout << typeid(T).name() << endl;
	cout << typeid(U).name() << endl;
	cout << t << endl;
	cout << u << endl; 
}
//typename 和 class混用 
template <typename T, int size>
void display(const T t) {
	for (int i = 0; i < size; i++) {
		cout << t << endl;
	}
}

template <typename T>
void display(const T t) {
	cout << t << endl;
}

int main(int argc, char **argv) {

	int a = 1, b =2;
	cout << t_max<int>(a, b) << endl;
	
	display<int, string>(3, "yjkh");
	display<int, 3>(10);
	display<char*>("asdfasdfa");
	return 0;
} 
