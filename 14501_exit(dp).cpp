#include <iostream>
#include <algorithm>
using namespace std;

int cnt;
int arr[2][15];
int cache[15];

int getres(int date) {
	if (date > cnt) {
		return -210000000;
	}
	if (date == cnt) {
		return 0;
	}
	if (cache[date] != -1) {
		return cache[date];
	}
	return max(getres(date + 1), getres(date+arr[0][date])+arr[1][date]);
}

int main() {
	cin >> cnt;
	for (int i = 0;i < cnt;i++) {
		cin >> arr[0][i];
		cin >> arr[1][i];
		cache[i] = -1;
	}
	int out = getres(0);
	cout << out;
	return 0;
}