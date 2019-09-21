#include <iostream>
using namespace std;
namespace my {
	#define MAX_ROW 8
	#define MAX_COL 8
	static int arr[MAX_ROW][MAX_COL] = {0};

	static int count = 0;
	//只需判断a[i][j]的上列直线、左右上对角线是否出现过1，
	//左横直线不需要判断，因为判断方向是从上到下，从左往右判断
	bool check(int row, int col) {
		//a[i][j]上列线判断
		for (int i = 0; i <= row; i++) {
			if (arr[i][col] == 1) {
				return false;
			}
		}
		//a[i][j]左上对角线判断
		for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
			if (1 == arr[i][j]) {
				return false;
			}
		}
		//a[i][j]右上对角线判断
		for (int i = row-1, j = col+1; i >= 0 && j < MAX_COL; i--, j++) {
			if (1 == arr[i][j]) {			
				return false;
			}
		}	
		return true;
	}
	
	void printArr() {
		for (int i = 0; i < MAX_ROW; i++) {
			for (int j = 0; j < MAX_COL; j++) {
				if (1 == arr[i][j]) {
					cout << "Q "; 
				} else {
					cout << "X ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	//确定行坐标row，然后该行的列坐标col从0开始，判断a[row][col]左右上对角线和上直线是否出现1
	//出现过，则col++,如果col == MAX_COL了，则退出该层递归，上一层坐标a[row][col]置为0
	//未出现，则a[row][col]=1,对下一行递归判断，row == MAX_ROW则打印成功的矩阵
	void findQueue(int row) {
		if (row == MAX_ROW) {
			count++;
			printArr();
			return;
		}
		
		for (int col = 0; col < MAX_COL; col++) {//深度回溯,递归算法
			if (check(row, col)) {
				arr[row][col] = 1;
				findQueue(row+1);
				arr[row][col] = 0;			
			}
		}	
	}
}
int main(void) {
	my::findQueue(0);
	cout << my::count << endl;
	system("pause");
	return 0;
}