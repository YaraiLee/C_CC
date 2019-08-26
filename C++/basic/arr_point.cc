#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int arr[5] = {0, 1, 2, 3, 4};
    printf("%p %p\n", &arr[1], &arr[0]);
    printf("%ld\n", (long long)&arr[1] - (long long)&arr[0]);
    printf("%ld\n", &arr[2] - &arr[0]);
    printf("%d\n", *(&arr[4] - 1));

    char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    char *p = char_arr;
    printf("*(p+1) = %c\n", *(p+1));
    char **q = &p;
    printf("**q = %c\n", **q);
    (*q)++;
    printf("%c\n", **q);
	//自增整个数组长度，获取最后一个字符数据	
    printf("%p %p\n", &char_arr, &char_arr+1);
    printf("%c\n", *(*(&char_arr+1)-1));
    return 0;
}
