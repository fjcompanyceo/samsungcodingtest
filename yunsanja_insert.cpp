#include <iostream>
using namespace std;

int val[11];
int n;
int cal[4];

int max_val = -2100000000;
int min_val = 2100000000;


void dfs(int cur_val, int cnt) {
	if (cnt == n) {
		if (cur_val > max_val) {
			max_val = cur_val;
		}
		if (cur_val < min_val) {
			min_val = cur_val;
		}
		return;
	}
	for (int i = 0;i <= 3;i++) {
		if (cal[i] != 0) {
			--cal[i];
			if (i == 0) {
				dfs(cur_val + val[cnt], cnt + 1);
			}
			else if (i == 1) {
				dfs(cur_val - val[cnt], cnt + 1);
			}
			else if (i == 2) {
				dfs(cur_val * val[cnt], cnt + 1);
			}
			else if (i == 3) {
				dfs(cur_val / val[cnt], cnt + 1);
			}
			++cal[i];
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> val[i];
	}
	for (int j = 0;j < 4;j++) {
		cin >> cal[j];
	}
	dfs(val[0], 1);
	cout << max_val << "\n";
	cout << min_val;
	return 0;

}



