#include <iostream>
#include <assert.h>

using namespace std;

/*
 * �����������Ƚ�������������汾�Ŵ�С�ĺ������� 1.2.3a �� 1.2.4b
 * �������: verson1: ��һ���汾���ַ���ָ��
 *          verson2: �ڶ����汾���ַ���ָ��
 * ���ز�����intֵ �������0 ��verson1�汾�� ���С��0 verson2�汾�� ����0 �����汾���
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
