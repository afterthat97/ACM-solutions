#include <iostream>
#include <cstring>
#include <stdio.h>
#define uint unsigned int
using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
unsigned char a[6][7], step[10], t[6][7], mark[6][7], ans[10], col;
uint max_combo, max_drops, min_len, ans_x, ans_y, px, py, q[50][2], front, tail, combo, drops, T;

inline void record_ans(uint leng){
	max_combo = combo;
	max_drops = drops;
	min_len = leng;
	ans_x = px;
	ans_y = py;
	for (uint i = 0; i < leng; i++)
		ans[i] = step[i];
}

inline void work(uint leng) {
	combo = drops = 0;
	for (uint i = 1; i <= 5; i++)
		for (uint j = 1; j <= 6; j++)
			t[i][j] = a[i][j];//先将原棋盘copy到临时棋盘t中

	while (1) {
		memset(mark, 0, sizeof(mark));
		bool move = 0;//判断本次是否有棋子被消除
		for (uint i = 1; i <= 5; i++)
			for (uint j = 1; j <= 4; j++)//判断是否有三个连续相同棋子在同一行
				if (t[i][j] == t[i][j + 1] && t[i][j] == t[i][j + 2] && t[i][j] > 65) {
					mark[i][j] = mark[i][j + 1] = mark[i][j + 2] = t[i][j];
					if (!move) move = 1;
				}
		for (uint j = 1; j <= 6; j++)
			for (uint i = 1; i <= 3; i++)//判断是否有三个连续相同棋子在同一列
				if (t[i][j] == t[i + 1][j] && t[i][j] == t[i + 2][j] && t[i][j] > 65) {
					mark[i][j] = mark[i + 1][j] = mark[i + 2][j] = t[i][j];
					if (!move) move = 1;
				}
		if (move == 0) break;

		for (uint i = 1; i <= 5; i++)
			for (uint j = 1; j <= 6; j++)
				if (mark[i][j] > 1) {//手写队列，统计combo和drops数量
					combo++;
					front = tail = 0;
					col = t[i][j];
					q[0][0] = i; q[0][1] = j;
					mark[i][j] = 1;
					while (front <= tail) {
						uint x = q[front][0], y = q[front][1];
						drops++;
						front++;
						for (uint k = 0; k < 4; k++) {
							uint nx = x + dx[k], ny = y + dy[k];
							if (nx == 0 || ny == 0 || nx == 6 || ny == 7) continue;
							if (mark[nx][ny] > 1 && t[nx][ny] == col) {
								q[++tail][0] = nx;
								q[tail][1] = ny;
								mark[nx][ny] = 1;
							}
						}
					}
				}
		for (uint j = 1; j <= 6; j++) {//进行消除操作
			uint h = 5;
			for (uint i = 5; i >= 1; i--)
				if (mark[i][j] != 1)
					t[h--][j] = t[i][j];//如果下面的棋子被消除了，上面的会掉下来
			for (uint i = h; i >= 1; i--)
				t[i][j] = 0;//没有棋子的地方就置0
		}
	}
	if (combo > max_combo)//记录答案
		record_ans(leng);
	else if (combo == max_combo)
		if (drops > max_drops)
			record_ans(leng);
		else if (drops == max_drops && leng < min_len)
			record_ans(leng);
}

inline void DFS(uint x, uint y, uint len) {
	if (len == 9) return;//棋子移动的path长度（即移动操作次数）不超过9次
	for (uint i = 0; i < 4; i++) {
		uint nx = x + dx[i], ny = y + dy[i];
		if (nx == 0 || ny == 0 || nx == 6 || ny == 7) continue;//边界检测
		if (i == 0) {//x坐标+1，即向下走
			if (len > 0 && step[len - 1] == 'U') continue;//如果上一次是向上走的，那就continue
			step[len] = 'D';//记录本次步骤
		} else if (i == 1) {//y坐标+1，向右走
			if (len > 0 && step[len - 1] == 'L') continue;//如果上一次是向左走的，那就continue
			step[len] = 'R';
		} else if (i == 2) {//x坐标-1，即向上走
			if (len > 0 && step[len - 1] == 'D') continue;//如果上一次是向下走的，那就continue
			step[len] = 'U';
		} else {//y坐标-1，即向左走
			if (len > 0 && step[len - 1] == 'R') continue;//如果上一次是向右走的，那就continue
			step[len] = 'L';
		}
		swap(a[x][y], a[nx][ny]);//交换位置
		work(len + 1);//跑消除操作
		DFS(nx, ny, len + 1);//DFS该棋子到达的新位置
		swap(a[x][y], a[nx][ny]);
	}
}

int main() {
	scanf("%d", &T);
	for (int idx = 1; idx <= T; idx++) {
		for (int i = 1; i <= 5; i++)
			for (int j = 1; j <= 6; j++)
				cin >> a[i][j];
		max_combo = max_drops = 0;
		min_len = 100;
		for (px = 1; px <= 5; px++)
			for (py = 1; py <= 6; py++)
				DFS(px, py, 0);//枚举棋盘中所有棋子
		printf("Case #%d:\nCombo:%d Length:%d\n%d %d\n", idx, max_combo, min_len, ans_x, ans_y);
		for (uint i = 0; i < min_len; i++)
			printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}