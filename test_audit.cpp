#include<iostream>
//#include<vector>
#include<cstdio>
using namespace std;

int roomcnt;
int arr[1000000];
int total, side;

int main() {
	freopen("input.txt", "r", stdin);
	cin >> roomcnt;
	for (int i = 0;i < roomcnt;i++) {
		int temp;
		cin >> arr[i];
		
	}
	cin >> total >> side;
	long long cnt = 0;
	for (int i = 0;i < roomcnt; i++) {
		int flag = 0;
		while (arr[i] > 0) {
			if (!flag) {
				arr[i] -= total;
				flag = 1;
				cnt++;
			}
			else {
				if (arr[i] % side == 0) {
					cnt += arr[i] / side;
					break;
				}
				else {
					cnt += (arr[i] / side);
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}