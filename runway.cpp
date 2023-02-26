#include<iostream>
#include<vector>
using namespace std;

int cnt, len;
int tot_cnt;
int arr[100][100];
int check[100][100];

void setcheck() {
	for (int j = 0;j < cnt;j++) {
		int flag = 1;
		for (int i = 0;i < cnt - 1;i++) {
			if (arr[j][i] != arr[j][i + 1]) {
				if (abs(arr[j][i] - arr[j][i + 1]) > 1) {
					flag = 0;
					break;
				}
				if (arr[j][i] < arr[j][i + 1]) {
					int inflag = 1;
					if (i - len + 1 < 0) {
						flag = 0;
						break;
					}
					int temp = arr[j][i];
					for (int k = i;k >= i - len + 1;k--) {
						if (check[j][k] == 1 || arr[j][k] != temp) {
							flag = 0;
							inflag = 0;
							break;
						}
					}
					if (!inflag) {
						break;
					}
					for (int k = i;k >= i - len + 1;k--) {
						check[j][k] = 1;
					}
				}
				if (arr[j][i] > arr[j][i + 1]) {
					int inflag = 1; // 숫자 다른데 경사로 걸치가능 여부
					if (i + len - 1 > cnt - 1) {
						flag = 0;
						break;
					}
					int temp = arr[j][i + 1];
					for (int k = i + 1;k <= i + len;k++) {
						if (check[j][k] == 1 || arr[j][k] != temp) {
							flag = 0;
							inflag = 0;
							break;
						}
					}
					if (!inflag) {
						break;
					}
					for (int k = i + 1;k <= i + len;k++) {
						check[j][k] = 1;
					}

				}
			}

		}
		if (flag) {
			tot_cnt++;
		}
	}
	return;
}

void turn() {
	vector<vector<int>> tmp;
	for (int j = 0;j < cnt;j++) {
		vector<int> temp1;
		for (int i = 0;i < cnt;i++) {
			temp1.push_back(0);
		}
		tmp.push_back(temp1);
	}
	for (int j = 0;j < cnt;j++) {
		for (int i = 0;i < cnt;i++) {
			tmp[j][i] = arr[cnt-1-i][j];
		}
	}
	for (int j = 0;j < cnt;j++) {
		for (int i = 0;i < cnt;i++) {
			arr[j][i] = tmp[j][i];
		}
	}
	return;
}

void reset() {
	for (int j = 0;j < cnt;j++) {
		for (int i = 0;i < cnt;i++) {
			check[j][i] = 0;
		}
	}
}

int main() {
	
	//freopen("input.txt", "r", stdin);
	cin >> cnt >> len;
	for (int j = 0;j < cnt;j++) {
		for (int i = 0;i < cnt;i++) {
			cin >> arr[j][i];
		}
	}

	setcheck();
	turn();
	reset();
	setcheck();

	cout << tot_cnt;
	return 0;
}