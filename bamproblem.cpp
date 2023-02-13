#include<iostream>
#include<cstdio>

using namespace std;
int snake_y[10101];
int snake_x[10101];
char cmd[10001];
int arr[101][101];
int mapsize;
int applecnt;
int comcnt;

int cury = 1;
int curx = 1;
int tailidx = 0;

int main() {
	freopen("input.txt", "r", stdin);

	int time = 0;
	int dix[4] = { 1,0,-1,0 };
	int diy[4] = { 0,1,0,-1 };
	int didx = 0;
	cin >> mapsize;
	cin >> applecnt;
	for (int i = 0;i < applecnt;i++) {
		int ay, ax;
		cin >> ay >> ax;
		arr[ay][ax] = 1;
	}
	cin >> comcnt;
	for (int i = 0;i < comcnt;i++) {
		int idx;
		char com;
		cin >> idx >> com;
		cmd[idx] = com;
	}
	snake_y[time] = cury;
	snake_x[time] = curx;
	arr[cury][curx] = -1;
	tailidx = time;
	while (1) {
		if (time == 2) {
			int a = 1;
		}
		time++;
		cury += diy[didx];
		curx += dix[didx];
		if (cury > mapsize || cury < 1 || curx > mapsize || curx < 1 || arr[cury][curx] == -1) {
			break;
		}
		if (arr[cury][curx] == 1) {
			snake_y[time] = cury;
			snake_x[time] = curx;
			arr[cury][curx] = -1;
		}
		else if (arr[cury][curx] == 0) {
			snake_y[time] = cury;
			snake_x[time] = curx;
			arr[cury][curx] = -1;
			arr[snake_y[tailidx]][snake_x[tailidx]] = 0;
			tailidx++;
		}
		if (cmd[time] == 'L') {
			didx = (didx + 3) % 4;
		}
		if (cmd[time] == 'D') {
			didx = (didx + 1) % 4;
		}
	}
	cout << time;
	
}