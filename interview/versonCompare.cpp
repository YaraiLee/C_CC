#include <iostream>
#include <assert.h>

using namespace std;

/*
 * 函数描述：比较任意两个软件版本号大小的函数，如 1.2.3a 和 1.2.4b
 * 传入参数: verson1: 第一个版本号字符串指针
 *          verson2: 第二个版本号字符串指针
 * 返回参数：int值 如果大于0 则verson1版本大 如果小于0 verson2版本大 等于0 两个版本相等
 */
int compareVer(const char* verson1, const char* verson2) {
    assert(NULL != verson1 && NULL != verson2);
    const char* start1 = verson1;
    const char* start2 = verson2;

    while(1) {
        if (*start1 == '\0' || *start2 == '\0') {
           return *start1 - *start2;
        }
        if (*start1 == *start2) {
            start1++;
            start2++;
            continue;
        } else if (isdigit(*start1) && isdigit(*start2)) {
            return *start1 - *start2;
        } else if (isdigit(*start1) && !isdigit(*start2)){
            return *start1;
        } else if (!isdigit(*start1) && isdigit(*start2)) {
            return -(*start2);
        } else if (isalpha(*start1) && isalpha(*start2)) {
            return tolower(*start1) - tolower(*start2);
		} else if (*start1 == ' ' || *start2 == ' ') {
			return -255;
		}

        start1++;
        start2++;
    }
}

int main(void) {
	const char *str1 = "1.2.3a";
	const char *str2 = "1. 3.2b";
	cout << compareVer(str1, str2) << endl;

	system("pause");
	return 0;
}
