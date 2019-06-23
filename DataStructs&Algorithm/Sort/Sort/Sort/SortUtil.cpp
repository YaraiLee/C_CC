#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

//插入排序 稳定排序 O(n^2)
void InsertionSort(int *pData, int n) {
	assert(NULL != pData);
	int temp;
	for (int i = 1; i < n; i++) {
		temp = pData[i];
		int j = i - 1;
		for (; j >= 0 && pData[j] > temp; j--) {
			pData[j + 1] = pData[j];
		}
		pData[j+1] = temp;
	}
}
//冒泡排序 稳定 O（n^2）
void BubbleSort(int arr[], int n) {
	assert(NULL != arr);
	int temp;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (arr[j-1] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}
//改进冒泡排序 稳定 O（n^2）
void BubbleSortEx(int arr[], int n) {
	int temp;
	bool flag = true;
	int j = n - 1;
	while (flag)
	{
		flag = false;
		for (int i = 1; i <= j; i++) {
			if (arr[i - 1] > arr[i]) {
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				flag = true;
			}
		}
		j--;
	}
}
//划分函数实现
int partition(int arr[], int i, int j) {
	int temp = arr[i];
	while (i < j) {
		while (arr[j] >= temp && i < j) j--;
		if (i < j) arr[i++] = arr[j];
		while (arr[i] <= temp && i < j) i++;
		if (i < j) arr[j--] = arr[i];
	}
	arr[i] = temp;
	return i;
}
//快速排序 不稳定 O(nlogn)
void QuickSort(int arr[], int i, int j) {
	assert(NULL != arr);
	int k;
	if (i < j) {
		k = partition(arr, i, j);
		QuickSort(arr, i, k - 1);
		QuickSort(arr, k + 1, j);
	}
}
template <typename T>
int partitionEx(vector<T>& vec, int i, int j) {
	T temp = vec[i];
	while (i < j) {
		while (vec[j] >= temp && i < j) j--;
		if (i < j) vec[i++] = vec[j];
		while (vec[i] <= temp &&i < j) i++;
		if (i < j) vec[j--] = vec[i];
	}
	vec[i] = temp;
	return i;
}
template <typename T>
void QuickSortEx(vector<T>& vec, int i, int j) {
	int k;
	if (i < j) {
		k = partitionEx<T>(vec, i, j);
		QuickSortEx<T>(vec, i, k - 1);
		QuickSortEx<T>(vec, k + 1, j);
	}
}
//选择排序 不稳定 O（n^2）
void SelectSort(int a[], int n) {
	int min;
	int temp;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
//把两个数组合并
void Merge(int a[], int s1, int e1, int s2, int e2, int b[]) {
	int k = s1;
	int i = s1;
	while (s1 <= e1 && s2 <= e2) {
		if (a[s1] <= a[s2]) {
			b[k++] = a[s1++];
		}
		else {
			b[k++] = a[s2++];
		}
	}

	while (s1 <= e1) b[k++] = a[s1++];
	while (s2 <= e2) b[k++] = a[s2++];
	k--;
	while (i <= k) {
		a[i] = b[i];
		i++;
	}
}
template <typename T>
void MergeEx(vector<T>& veca, int s1, int e1, int s2, int e2) {
	cout << s1 << " " << s2 << endl;
	vector<T> vecb;
	int k = s1;
	while (s1 <= e1 && s2 <= e2) {
		if (veca[s1] <= veca[s2]) {
			vecb.push_back(veca[s1]);
			s1++;
		}
		else {
			vecb.push_back(veca[s2]);
			s2++;
		}
	}
	while (s1 <= e1) {
		vecb.push_back(veca[s1]);
		s1++;
	}

	while (s2 <= e2) {
		vecb.push_back(veca[s2]);
		s2++;
	}
	
	for (auto v : vecb) {
		veca[k++] = v;
	}
}
template <typename T>
void MergeSortEx(vector<T>& vec, int i, int j) {
	int k;
	if (i < j) {
		k = i + (j - i) / 2;
		MergeSortEx<T>(vec, i, k);
		MergeSortEx<T>(vec, k + 1, j);
		MergeEx<T>(vec, i, k, k + 1, j);
	}
}
//归并排序 稳定 O(nlogn)
void MergeSort(int a[], int i, int j, int b[]) {
	assert(NULL != a && NULL != b);
	int k;
	if (i < j) {
		k = i + (j - i) / 2;
		MergeSort(a, i, k, b);
		MergeSort(a, k + 1, j, b);
		Merge(a, i, k, k + 1, j, b);
	}
}

/************************************************************************/
/* 偏移量                                                                     */

/************************************************************************/
typedef struct A
{
	char c;
	short int a;
	int b;
	double d;
}ST_A;

//#define STRUCT_OFFSET(TYPE, MEMBER) ((unsigned long)(&(((TYPE*)0)->MEMBER)))

#define OFFSET(TYPE , MEMBER)((unsigned long)(&(((TYPE *)0)->MEMBER)))

//int main(void)
//{
//	unsigned long offset = OFFSET(ST_A, b);
//
//	printf("%ld\n", offset);
//
//	ST_A sta;
//
//	offset = (unsigned long)(&(sta.a)) - (unsigned long)(&(sta.c));
//
//	printf("%p\n", &sta);
//	printf("%p\n", &(sta.c));
//	printf("%ld\n", offset);
//
//	system("pause");
//	return 0;
//}


int main(void) {
	int arr[] = {2,3,4,5,1,3,0};
	vector<int> vec{ 2,3,4,5,1,3,0};
	vector<double> fvec{ 0.1, 3.1, 1.1, 0, -1.1, 2.9 };
	//InsertionSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSortEx(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//MergeSortEx<int>(vec, 0, vec.size()-1);
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));

	int *ptr = new int[sizeof(arr)/sizeof(arr[0])];

	MergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, ptr);

	for (auto a : arr) {
		cout << a << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}