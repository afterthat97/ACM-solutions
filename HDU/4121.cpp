#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
const int hx[8] = { -2,-2,-1,1,2,2,1,-1 };
const int hy[8] = { -1,1,2,2,1,-1,-2,-2 };//01 23 34 67

int n, tx, ty, red[8][2];
char a[11][10], temp;

bool avail(int x, int y) {
	if (x > 10 || x < 1 || y < 1 || y > 9)
		return false;
	return true;
}

bool judge(int nx, int ny) {//success escape
	temp = a[nx][ny];
	a[tx][ty] = 0;
	a[nx][ny] = 'T';
	//outa();
	for (int i = 0; i < n; i++)
		if (red[i][0] != nx || red[i][1] != ny) {
			int cx = red[i][0];
			int cy = red[i][1];
			if (a[red[i][0]][red[i][1]] == 'G') {//red genual
				if (red[i][1] != ny) continue;
				int no_man = 1;
				for (int x = nx + 1; x < red[i][0]; x++)
					if (a[x][ny] > 0) no_man = 0;
				if (no_man) return false;
			} else if (a[red[i][0]][red[i][1]] == 'H') {// red horse
				for (int k = 0; k < 4; k++)
					if (avail(cx + dx[k], cy + dy[k]))
						if (a[cx + dx[k]][cy + dy[k]] == 0) {
							if (cx + hx[2 * k] == nx &&  cy + hy[2 * k] == ny) return false;
							if (cx + hx[2 * k + 1] == nx &&  cy + hy[2 * k + 1] == ny) return false;
						}
			} else if (a[red[i][0]][red[i][1]] == 'R') {// car
				if (cx == nx) {
					int no_man = 1;
					if (cy > ny) {
						for (int x = ny + 1; x < cy; x++)
							if (a[cx][x] > 0) no_man = 0;
						if (no_man) return false;
					} else {
						for (int x = cy + 1; x < ny; x++)
							if (a[cx][x] > 0) no_man = 0;
						if (no_man) return false;
					}
				} else if (cy == ny) {
					int no_man = 1;
					if (cx > nx) {
						for (int x = nx + 1; x < cx; x++)
							if (a[x][ny] > 0) no_man = 0;
						if (no_man) return false;
					} else {
						for (int x = cx + 1; x < nx; x++)
							if (a[x][ny] > 0) no_man = 0;
						if (no_man) return false;
					}
				}
			} else {//pao
				if (cx == nx) {
					int man = 0;
					if (cy > ny) {
						for (int x = ny + 1; x < cy; x++)
							if (a[cx][x] > 0) man++;
						if (man == 1) return false;
					} else {
						for (int x = cy + 1; x < ny; x++)
							if (a[cx][x] > 0) man++;
						if (man == 1) return false;
					}
				} else if (cy == ny) {
					int man = 0;
					if (cx > nx) {
						for (int x = nx + 1; x < cx; x++)
							if (a[x][ny] > 0) man++;
						if (man == 1) return false;
					} else {
						for (int x = cx + 1; x < nx; x++)
							if (a[x][ny] > 0) man++;
						if (man == 1) return false;
					}
				}
			}
		}
	a[nx][ny] = temp;
	return 1;
}

int main() {
	while (scanf("%d %d %d", &n, &tx, &ty) == 3 && n && tx && ty) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			char ch;
			cin >> ch >> red[i][0] >> red[i][1];
			a[red[i][0]][red[i][1]] = ch;
		}
		bool succ = 0;
		for (int move = 0; move < 4; move++) {
			int nx = tx + dx[move];
			int ny = ty + dy[move];
			if (ny > 6 || ny < 4 || nx < 1 || nx > 3) continue;
			if (judge(nx, ny)) succ = 1;
			a[nx][ny] = temp;
		}
		if (succ) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
