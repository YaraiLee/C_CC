#include <iostream>
#include <stack>
using namespace std;

bool isValid(const char* str) {
	if (NULL == str || strlen(str) != 0) {
		return true;
	}
	
	stack<char> srcStack;
	stack<char> needStack;
	char needCh = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (needCh != str[i]) {
			srcStack.push(str[i]);
			switch (str[i]) {
				case '[':
					if (needCh != 0) {
						needStack.push(needCh);
					}
					needCh = ']';
					break;
				case '(':
					if (needCh != 0) {
						needStack.push(needCh);
					}
					needCh = ')';	
				break;
				default:
					return false;
			}
		} else {
			srcStack.pop();
			if (!needStack.empty()) {
				needCh = needStack.top();
				needStack.pop();	
			}
		}
	}
	
	return (srcStack.empty() && needStack.empty()) ? true : false; 
}

int main(int argc, char* argv[]) {
	const char str[] = "[()]]";
	if (isValid(str)) {
		cout << str << " is valid" << endl;
	} else {
		cout << str << " is invalid" << endl;
	}
	system("pause");
	return 0;	
}