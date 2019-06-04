#include <stdio.h>
#include <string.h>

void sort(char **pa, int n)//冒泡排序
{
    int i, j;
    char *tmp = NULL;

    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-1-i; j++){
            if(strcmp(*(pa+j), *(pa+j+1)) > 0){
                tmp = *(pa + j);
                *(pa + j) = *(pa + j + 1);
                *(pa + j + 1) = tmp;
            }
        }
    }
}

void print_arr(int (*ptr)[3])
{
	printf("%d\n", *(ptr+2)[0]);//第二行，第一列 
}

int main(int argc, char *argv[])
{
	sort(argv, argc);
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	int arr[2][3] = {{1,2,3},{4,5,6}};
	print_arr(arr);
	return 0;
}  