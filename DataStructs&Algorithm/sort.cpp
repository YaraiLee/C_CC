#include <stdio.h>
#include <string.h>
//插入排序-->稳定
void insert_sort(int arr[], int size)
{
	int i, j, v;
	for (i = 1; i < size; i++)
	{
		for (v = arr[i], j = i - 1; j >= 0 && v < arr[j]; j--)
		{	
				arr[j+1] = arr[j];
		}					
		arr[j+1] = v;	
	}
} 

//选择排序-->不稳定 
void select_sort(int arr[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		int min, j; 
		for (min = arr[i], j = i+1; j < size; j++)
		{
			if (arr[j] < min)
			{
				arr[i] = arr[j];
				arr[j] = min;
				min = arr[i];
			}
		}
	}
} 
	//冒泡排序-->稳定 
void bubble_sort(int arr[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			} 
		}
	}
} 

int main(int argc, char *argv[])
{
	int array[] = {9,2,4,6,2,1,4,9,0};
#if 1	
	printf("排序前:\n"); 
	for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{	
		printf("[%d]=%d ", i, array[i]);	
	}
	printf("\n");

	insert_sort(array, sizeof(array)/sizeof(array[0]));

//	select_sort(array, sizeof(array)/sizeof(array[0]));

//	bubble_sort(array, sizeof(array)/sizeof(array[0])); 
	printf("排序后:\n"); 
	for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		printf("[%d]=%d ", i, array[i]);
	}	
	printf("\n");
#endif	
}
