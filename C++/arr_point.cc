#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int arr[5] = {0, 1, 2, 3, 4};
    printf("%p %p\n", &arr[1], &arr[0]);
    printf("%ld\n", (long)&arr[1] - (long)&arr[0]);
    printf("%ld\n", &arr[1] - &arr[0]);

    char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    char *p = char_arr;
    char **q = &p;
    printf("%c\n", **q);
    (*q)++;
    printf("%c\n", **q);
    return 0;
}