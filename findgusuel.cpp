#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <queue>

using namespace std;
char arr[10][11];
int ny, nx;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

struct Node {
	int by;
	int bx;
	int ry;
	int rx;
	int cnt;
};

queue<Node> q;
Node sp;
int bfs() {
	int ret = -1;
	int visited[10][10][10][10] = { 0 };
	for (int j = 0;j < ny;j++) {
		for (int i = 0; i < nx;i++) {
			if (arr[j][i] == 'B') {
				sp.by = j;
				sp.bx = i;
			}
			if (arr[j][i] == 'R') {
				sp.ry = j;
				sp.rx = i;
			}
		}
	}
	visited[sp.ry][sp.rx][sp.by][sp.bx] = 1;
	sp.cnt = 0;
	q.push(sp);
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		if (cur.cnt > 10) {
			break;
		}
		if (arr[cur.ry][cur.rx] == 'O' && arr[cur.by][cur.bx] != 'O') {
			ret = cur.cnt;
			break;
		}
		if (arr[cur.ry][cur.rx] != 'O' && arr[cur.by][cur.bx] == 'O') {
			continue;
		}
		for (int i = 0;i <= 3;i++) {
			Node now;
			now.by = cur.by + dy[i];
			now.bx = cur.bx + dx[i];
			now.ry = cur.ry + dy[i];
			now.rx = cur.rx + dx[i];
			now.cnt = cur.cnt + 1;
			while (1) {
				if (arr[now.ry][now.rx] == '#') {
					now.ry -= dy[i];
					now.rx -= dx[i];
					break;
				}
				if (arr[now.ry][now.rx] == 'O') {
					break;
				}
				now.ry += dy[i];
				now.rx += dx[i];
			}
			while (1) {
				if (arr[now.by][now.bx] == '#') {
					now.by -= dy[i];
					now.bx -= dx[i];
					break;
				}
				if (arr[now.by][now.bx] == 'O') {
					break;
				}
				now.by += dy[i];
				now.bx += dx[i];
			}
			if (now.ry == now.by && now.rx == now.bx) {
				if (arr[now.ry][now.rx] != 'O') {
					int lr = abs(now.ry - cur.ry) + abs(now.rx - cur.rx);
					int lb = abs(now.by - cur.by) + abs(now.bx - cur.bx);
					if (lr > lb) {
						now.ry -= dy[i], now.rx -= dx[i];
					}
					else {
						now.by -= dy[i], now.bx -= dx[i];
					}

				}
				else {
					continue;
				}
			}
			if (visited[now.ry][now.rx][now.by][now.bx] == 0) {
				visited[now.ry][now.rx][now.by][now.bx] = 1;
				q.push(now);
			}
		}
	}
	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> ny >> nx;
	for (int j = 0;j < ny;j++) {
		for (int i = 0;i < nx;i++) {
			cin >> arr[j][i];
		}
	}
	int ret = bfs();
	cout << ret;
	//system("pause");

	return 0;
}