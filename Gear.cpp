#include<iostream>
using namespace std;

char arr[4][9];
int cnt;
int rotcheck[4] = { 0 };

void rotleft(int tn);

void rotright(int tn) {
	if (tn - 1 >= 0 && tn - 1 <= 2) {
		if (arr[tn][6] != arr[tn - 1][2] && rotcheck[tn - 1] == 0) {
			rotcheck[tn - 1] = 1;
			rotleft(tn - 1);
		}
		if (arr[tn][6] == arr[tn - 1][2]) {
			rotcheck[tn - 1] = 1;
		}
	}
	if (tn + 1 >= 1 && tn + 1 <= 3) {
		if (arr[tn][2] != arr[tn + 1][6] && rotcheck[tn + 1] == 0) {
			rotcheck[tn + 1] = 1;
			rotleft(tn + 1);
		}
		if (arr[tn][6] == arr[tn + 1][2]) {
			rotcheck[tn + 1] = 1;
		}
	}
	char temp = '\0';
	temp = arr[tn][7];
	for (int i = 6;i >= 0;i--) {
		arr[tn][i + 1] = arr[tn][i];
	}
	arr[tn][0] = temp;
	return;
}

void rotleft(int tn) {
	if (tn - 1 >= 0 && tn - 1 <= 2) {
		if (arr[tn][6] != arr[tn - 1][2] && rotcheck[tn - 1] == 0) {
			rotcheck[tn - 1] = 1;
			rotright(tn - 1);
		}
		if (arr[tn][6] == arr[tn - 1][2]) {
			rotcheck[tn - 1] = 1;
		}
	}
	if (tn + 1 >= 1 && tn + 1 <= 3) {
		if (arr[tn][2] != arr[tn + 1][6] && rotcheck[tn + 1] == 0) {
			rotcheck[tn + 1] = 1;
			rotright(tn + 1);

		}
		if (arr[tn][6] == arr[tn + 1][2]) {
			rotcheck[tn + 1] = 1;
		}
	}
	char temp = '\0';
	temp = arr[tn][0];
	for (int i = 1;i <= 7;i++) {
		arr[tn][i - 1] = arr[tn][i];
	}
	arr[tn][7] = temp;
	return;
}

void run_rot(int tn, int dir) {
	if (dir == 1) {
		rotcheck[tn] = 1;
		rotright(tn);
	}
	else if (dir == -1) {
		rotcheck[tn] = 1;
		rotleft(tn);
	}

	return;
}

void reset() {
	for (int i = 0;i <= 3;i++) {
		rotcheck[i] = 0;
	}
}

int main() {
	
	freopen("input.txt", "r", stdin);
	for (int i = 0;i <= 3;i++) {
		cin >> arr[i];
	}
	cin >> cnt;
	for (int i = 0;i < cnt;i++) {
		int tob_num, dir;
		cin >> tob_num >> dir;
		run_rot(--tob_num, dir);
		reset();
	}
	int tot_val = 0;
	for (int i = 0;i <= 3;i++) {
		if (i == 0) {
			if (arr[i][0] == '1') {
				tot_val += 1;
			}
		}
		if (i == 1) {
			if (arr[i][0] == '1') {
				tot_val += 2;
			}
		}
		if (i == 2) {
			if (arr[i][0] == '1') {
				tot_val += 4;
			}
		}
		if (i == 3) {
			if (arr[i][0] == '1') {
				tot_val += 8;
			}
		}
	}
	cout << tot_val;
	return 0;
}