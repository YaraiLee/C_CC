#include <iostream>
/**
	实现写一个函数，将字符串翻转，翻转方式如下："I am a student" 反转成“"student a am I"，不借助任何库函数
*/


//实现从start到end字符交换 
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
/*	翻转整个字符串 */ 
void reverseStr(char* str) {
	if (NULL != str) {
		char *start = str, *end = str;
		while(*end != '\0') end++;
		end--;
		swap(start, end);
	}
} 
/*	翻转整个单词 */ 
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