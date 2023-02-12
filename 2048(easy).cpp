
#include<iostream>

using namespace std;

int ms;
int output;

struct BOARD {
	int arr[20][20];
	void rotate() {
		int temp[20][20];
		for (int y = 0;y < ms;y++) {
			for (int x = 0;x < ms;x++) {
				temp[y][x] = arr[ms-1-x][y]; //90도 회전
			}
		}
		for (int y = 0;y < ms;y++) {
			for (int x = 0;x < ms;x++) {
				arr[y][x] = temp[y][x]; //90도 회전
			}
		}
		return;
	}
	int getmax() {
		int ret = 0;
		for (int j = 0;j < ms;j++) {
			for (int i = 0;i < ms;i++) {
				if (arr[j][i] > ret) {
					ret = arr[j][i];
				}
			}
		}
		return ret;
	}
	void up() {
		int temp[20][20] = { 0, };
		for (int x = 0;x < ms;x++) {
			int flag = 0;
			int taridx = -1;
			for (int y = 0;y < ms;y++) {
				if (arr[y][x] == 0) {
					continue;
				}
				if (flag == 1 && temp[taridx][x] == arr[y][x]) {
					temp[taridx][x] *= 2;
					flag = 0;
				}
				else {
					temp[++taridx][x] = arr[y][x];
					flag = 1;
				}	
			}
			for (++taridx;taridx < ms;++taridx) {
				temp[taridx][x] = 0;
			}
		}
		for (int y = 0;y < ms;y++) {
			for (int x = 0;x < ms;x++) {
				arr[y][x] = temp[y][x];
			}
		}
	}
};

void dfs(BOARD board, int cnt) {
	if (cnt == 5) {
		int temp = board.getmax();
		if (output < temp) {
			output = temp;
		}
		return;
	}


	for (int i = 0;i <= 3;i++) {
		BOARD next = board;
		int tempmax = board.getmax();
		if (output < tempmax) {
			output = tempmax;
		}
		next.up();
		dfs(next, cnt + 1);
		board.rotate();
		int a = 1;

		
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> ms;
	BOARD board;
	for (int i = 0;i < ms;i++) {
		for (int j = 0;j < ms;j++) {
			cin >> board.arr[i][j];
		}
	}
	
	dfs(board, 0);

	cout << output;
	//system("pause");
	return 0;
}