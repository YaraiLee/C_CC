#include <iostream>

using namespace std;

//暴力破解 O（n^3） 
int maxSubArr(int a[], int n, int& sum) {
	int index = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int subSum = 0;
			for (int k = i; k <= j; k++) {
				subSum += a[k];	
			}
			if (subSum > sum) {
				sum = subSum;
				index = i;
			}
		}	
	}
	return index;
}
//贪心法 O(n) 
int maxSubArrEx(int a[], int n, int& sum) {
	int subSum = INT_MIN;
	int index = 0;
	for (int i = 0; i < n; ++i) {
		subSum += a[i];
		
		if (subSum < a[i]) {//i之前的子数组和为负数，丢弃，从i重新累计subSum 
			index = i;
			subSum = a[i];
		}
		if (subSum > sum) {
			sum = subSum;
		} 
	}
	return index;
}

int main(void) {
	int a[] = {1,2,3,-1,-10,2,-3,4,3,7,-1, 2};
	int sum = 0;
	int index = maxSubArr(a, sizeof(a)/sizeof(a[0]), sum);
	
	cout << "index = " << index << endl;
	cout << sum << endl;
	system("pause");
	return 0;
} 