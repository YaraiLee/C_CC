#include <iostream>
using namespace std;
namespace my {
	#define MAX_ROW 8
	#define MAX_COL 8
	static int arr[MAX_ROW][MAX_COL] = {0};

	static int count = 0;
	bool check(int row, int col) {
		for (int i = 0; i < MAX_ROW; i++) {
			if (arr[i][col] == 1) {
				return false;
			}
		}
		for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
			if (1 == arr[i][j]) {
				return false;
			}
		}
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
	void findQueue(int row) {
		if (row == MAX_ROW) {
			my::count++;
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