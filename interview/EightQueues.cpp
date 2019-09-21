#include <iostream>
using namespace std;
namespace my {
	#define MAX_ROW 8
	#define MAX_COL 8
	static int arr[MAX_ROW][MAX_COL] = {0};

	static int count = 0;
	
	bool check(int row, int col) {
		//a[i][j]左横线判断
		for (int j = 0; j <= col; j++) {
			if (1 == arr[row][j]) {
				return false;
			}
		}
		//a[i][j]直上线判断
		for (int i = 0; i <= row; i++) {
			if (arr[i][col] == 1) {
				return false;
			}
		}
		//a[i][j]左上斜线判断
		for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
			if (1 == arr[i][j]) {
				return false;
			}
		}
		//a[i][j]右上斜线判断
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
	//矩阵填充是按列优先，从左往右（从大到小），确定一列然后判断该列每行元素
	//check只需判断该点所在行的上侧和列的左侧（包含该列、行）
	void findQueue(int row) {
		if (row == MAX_ROW) {
			count++;
			printArr();
			return;
		}
		
		for (int col = 0; col < MAX_COL; col++) {
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