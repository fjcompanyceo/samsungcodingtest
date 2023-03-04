#include<iostream>
using namespace std;

struct cctv {
	int cy;
	int cx;
	int type;
};

int turncnt[6] = { 0,4,2,4,4,1 };

cctv ctarr[8];
int final_cnt;
int col, row;
int mincnt = 100;
int arr[8][8];
int temp[8][8];

void save(int temp[8][8], int arr[8][8]) {
	for (int j = 0;j < col;j++) {
		for (int i = 0;i < row;i++) {
			temp[j][i] = arr[j][i];
		}
	}
}

void backup(int arr[8][8], int temp[8][8]) {
	for (int j = 0;j < col;j++) {
		for (int i = 0;i < row;i++) {
			arr[j][i] = temp[j][i];
		}
	}
}

void setcctv(int dir,int cy, int cx) {
	if (dir > 3) {
		dir = dir % 4;
	}
	if (dir == 0) {
		for (int j = cy - 1;j >= 0;j--) {
			if (arr[j][cx] == 6) {
				break;
			}
			arr[j][cx] = -1;
		}
	}
	if (dir == 1) {
		for (int i = cx + 1;i < row;i++) {
			if (arr[cy][i] == 6) {
				break;
			}
			arr[cy][i] = -1;
		}
	}
	if (dir == 2) {
		for (int j = cy + 1;j < col;j++) {
			if (arr[j][cx] == 6) {
				break;
			}
			arr[j][cx] = -1;
		}
	}
	if (dir == 3) {
		for (int i = cx - 1;i >= 0;i--) {
			if (arr[cy][i] == 6) {
				break;
			}
			arr[cy][i] = -1;
		}
	}
}

void dfs(int nu) {
	if (nu == final_cnt) {
		int z_cnt = 0;
		for (int j = 0;j < col;j++) {
			for (int i = 0;i < row;i++) {
				if (arr[j][i] == 0) {
					z_cnt++;
				}
			}
		}
		if (z_cnt < mincnt) {
			mincnt = z_cnt;
		}
		return;
	}
	int temp[8][8] = { 0, };
	save(temp, arr);
	if (ctarr[nu].type == 1) {
		for (int i = 0;i < turncnt[1];i++) {
			setcctv(i,ctarr[nu].cy,ctarr[nu].cx);
			dfs(nu + 1);
			backup(arr, temp);

		}
	}
	else if (ctarr[nu].type == 2) {
		for (int i = 0;i < turncnt[2];i++) {
			setcctv(i, ctarr[nu].cy, ctarr[nu].cx);
			setcctv(i+2, ctarr[nu].cy, ctarr[nu].cx);
			dfs(nu + 1);
			backup(arr, temp);
		}
	}
	else if (ctarr[nu].type == 3) {
		for (int i = 0;i < turncnt[3];i++) {
			setcctv(i, ctarr[nu].cy, ctarr[nu].cx);
			setcctv(i+1, ctarr[nu].cy, ctarr[nu].cx);
			dfs(nu + 1);
			backup(arr, temp);
		}
	}
	else if (ctarr[nu].type == 4) {
		for (int i = 0;i < turncnt[4];i++) {
			setcctv(i, ctarr[nu].cy, ctarr[nu].cx);
			setcctv(i + 1, ctarr[nu].cy, ctarr[nu].cx);
			setcctv(i + 3, ctarr[nu].cy, ctarr[nu].cx);
			dfs(nu + 1);
			backup(arr, temp);
		}
	}
	else if (ctarr[nu].type == 5) {
		for (int i = 0;i < turncnt[5];i++) {
			setcctv(i, ctarr[nu].cy, ctarr[nu].cx);
			setcctv(i + 1, ctarr[nu].cy, ctarr[nu].cx);
			setcctv(i + 2, ctarr[nu].cy, ctarr[nu].cx);
			setcctv(i + 3, ctarr[nu].cy, ctarr[nu].cx);
			dfs(nu + 1);
			backup(arr, temp);
		}
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	cin >> col >> row;
	for (int j = 0;j < col;j++) {
		for (int i = 0;i < row;i++) {
			cin >> arr[j][i];
		}
	}

	int idx = 0;
	for (int j = 0;j < col;j++) {
		for (int i = 0;i < row;i++) {
			if (arr[j][i] != 0 && arr[j][i] != 6) {
				ctarr[idx].cy = j;
				ctarr[idx].cx = i;
				ctarr[idx].type = arr[j][i];
				idx++;
			}
		}
	}
	final_cnt = idx;

	dfs(0);
	cout << mincnt;
	return 0;
}