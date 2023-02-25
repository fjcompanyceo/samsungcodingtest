#include<iostream>
using namespace std;

int arr[20][20];
int cnt;
int check[20];
int mindiff = 2100000000;
int divmax = 0;
int cntval = 0;

void dfs(int num) {
	if (num == cnt) {
		if (cntval != divmax) {
			return;
		}
		int t1=0, t2=0;
		for (int j = 0;j < cnt;j++) {
			for (int i = j+1;i < cnt;i++) {
				if (check[j] == 1 && check[i] == 1) {
					t1 += arr[j][i];
					t1 += arr[i][j];
				}
				if (check[j] == 0 && check[i] == 0) {
					t2 += arr[j][i];
					t2 += arr[i][j];
				}
			}
		}
		int temp = abs(t1 - t2);
		if (temp < mindiff) {
			mindiff = temp;
		}
		return;
	}
	if (cntval < divmax) {
		check[num] = 1;
		cntval++;
		dfs(num + 1);
		cntval--;
		check[num] = 0;
	}
	dfs(num + 1);

	return;
}

int main() {

	freopen("input.txt", "r", stdin);
	cin >> cnt;
	divmax = cnt / 2;
	for (int j = 0;j < cnt;j++) {
		for (int i = 0;i < cnt;i++) {
			cin >> arr[j][i];
		}
	}
	dfs(0);
	cout << mindiff;
	return 0;
}