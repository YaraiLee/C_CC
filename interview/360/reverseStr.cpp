#include <iostream>
/**
	ʵ��дһ�����������ַ�����ת����ת��ʽ���£�"I am a student" ��ת�ɡ�"student a am I"���������κο⺯��
*/


//ʵ�ִ�start��end�ַ����� 
using namespace std;
void swap(char* start, char* end) {
	if (NULL != start && NULL != end) {
		while (start < end) {
			char temp = *start;
			*start = *end;
			*end = temp;
			start++;
			end--;
		}
	}
}
/*	��ת�����ַ��� */ 
void reverseStr(char* str) {
	if (NULL != str) {
		char *start = str, *end = str;
		while(*end != '\0') end++;
		end--;
		swap(start, end);
	}
} 
/*	��ת�������� */ 
void reverseWord(char* str) {
	if (NULL != str) {
		char *start = str, *end = str;
		while (true) {		
			while (*end != ' ' && *end != '\0') end++;
			end--;
			swap(start, end);
			end++;
			if (*end == '\0') {
				break;
			} else {
				end++;
				start = end;
			}
		}
	}
} 

int main(void) {
	char str[] = "I am a student";
	reverseStr(str);
	reverseWord(str);
	cout << str << endl;	
	system("pause");
	return 0;
} 