#include <iostream>
using namespace std;

int arr[21][21];
int cm[401];
int y;
int x;
int cmcnt;
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };
int dice[7] = { 0, };
int sy = 0;
int sx = 0;
void diceflip(int dir) {
	int tempdic[7];
	int temp = 0;
	switch (dir) {
	case 1:
	    temp = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = temp;
		break;
	case 4:
		temp = dice[6];
		dice[6] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
		break;
	case 2:
		temp = dice[6];
		dice[6] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
		break;
	case 3:
		temp = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = temp;
		break;
	default:
		break;
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	cin >> y >> x;
	cin >> sy >> sx;
	cin >> cmcnt;

	for (int j = 0;j < y;j++) {
		for (int i = 0;i < x;i++) {
			cin >> arr[j][i];
		}
	}
	for (int i = 0;i < cmcnt;i++) {
		cin >> cm[i];
	}
	for (int i = 0;i < cmcnt;i++) {
		diceflip(cm[i]);
		int cy = sy + dy[cm[i]];
		int cx = sx + dx[cm[i]];
		sy = cy;
		sx = cx;
		if (cy < 0 || cy >= y || cx < 0 || cx >= x) {
			continue;
		}
		if (arr[cy][cx] == 0) {
			arr[cy][cx] = dice[6];
		}
		else {
			dice[6] = arr[cy][cx];
			arr[cy][cx] = 0;
		}
		cout << dice[1] << endl;
	}
	return 0;
}