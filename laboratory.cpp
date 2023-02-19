#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int col, row, ret;
int arr[8][8] = { 0 };

const int dy[4] = { 0,-1,0,1 };
const int dx[4] = { 1,0,-1,0 };

void bfs() {
	queue<int> q;
	int backup[8][8];
	int visited[8][8] = { 0 };
	for (int j = 0;j < col;j++) {
		for (int i = 0;i < row;i++) {
			backup[j][i] = arr[j][i];
			if (arr[j][i] == 2) {
				q.push(j * 10 + i);
			}
		}
	}
	while (!q.empty()) {
		int temp = q.front(); q.pop();
		int ty, tx;
		ty = temp / 10;
		tx = temp % 10;
		visited[ty][tx] = 1;
		for (int i = 0;i <= 3;i++) {
			int cy, cx;
			cy = ty + dy[i];
			cx = tx + dx[i];
			if (cy < 0 || cy >= col || cx < 0 || cx >= row) {
				continue;
			}
			if (visited[cy][cx] == 0 && backup[cy][cx] == 0) {
				backup[cy][cx] = 2;
				q.push(cy * 10 + cx);
			}
		}
	}
	int cand = 0;

	for (int j = 0;j < col;j++) {
		for (int i = 0;i < row;i++) {
			if (backup[j][i] == 0) {
				cand++;
			}
		}
	}
	if (cand > ret) {
		if (ret == 46) {
			int a = 1;
		}
		ret = cand;
	}

	
}

void setbfs(int cnt, int sy, int sx) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int y = sy;y < col;y++) {
		for (int x = sx;x < row;x++) {
			if (arr[y][x] == 0) {
				arr[y][x] = 1;
				setbfs(cnt + 1, y , x );
				arr[y][x] = 0;
			}
		}
		sx = 0;
	}
	

}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> col >> row;
	for (int j = 0;j < col;j++) {
		for (int i = 0;i < row;i++) {
			cin >> arr[j][i];
		}
	}
	setbfs(0,0,0);

	cout << ret;
	return 0;

}