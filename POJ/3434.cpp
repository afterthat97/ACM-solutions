#include <iostream>
#include <stdio.h>
using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

struct snake {
	int head, tail, dir, q[100005][2];//手动queue
	bool exist;
	snake() { exist = 0; head = 0; tail = -1; }
};

char way[1005][1005];
bool used[1005][1005];
snake s[26];
int n, t, T;

int main() {
	scanf("%d %d", &n, &T);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			while (1) {
				way[i][j] = getchar();
				if (way[i][j] >= 'a' && way[i][j] <= 'z') break;
				if (way[i][j] >= 'A' && way[i][j] <= 'Z') break;
				if (way[i][j] == '.' || way[i][j] == '#') break;
			}
		}

	for (int i = 1; i <= n; i++)//从图中“识别”出蛇
		for (int j = 1; j <= n; j++)
			if (way[i][j] >= 'A' && way[i][j] <= 'Z') {
				int id = way[i][j] - 'A';
				s[id].exist = 1;
				s[id].q[++s[id].tail][0] = i;
				s[id].q[s[id].tail][1] = j;
				int x = i, y = j;
				char ch = way[i][j] + 'a' - 'A';
				bool find = 1;
				while (find) {
					find = 0;
					for (int i = 0; i < 4; i++)
						if (way[x + dx[i]][y + dy[i]] == ch && !used[x + dx[i]][y + dy[i]]) {
							if (way[x][y] == ch - 'a' + 'A')
								s[id].dir = (i + 2) % 4;
							used[x + dx[i]][y + dy[i]] = 1;
							x += dx[i]; y += dy[i];
							s[id].q[++s[id].tail][0] = x;
							s[id].q[s[id].tail][1] = y;
							find = true;
							break;
						}
				}
			}

	bool move = 0;//优化：如果本轮没有一条蛇动，那么之后也不会有任何的蛇会动了，直接输出即可
	for (int t = 0; t < T; t++) {
		move = 0;
		for (int i = 0; i < 26; i++)
			if (s[i].exist) {
				int d = s[i].dir, h = s[i].head, t = s[i].tail;
				if (way[s[i].q[h][0] + dx[d]][s[i].q[h][1] + dy[d]] == '.')
					d = d;//直行
				else if (way[s[i].q[h][0] + dx[(d + 1) % 4]][s[i].q[h][1] + dy[(d + 1) % 4]] == '.')
					d = (d + 1) % 4;//右拐
				else if (way[s[i].q[h][0] + dx[(d + 3) % 4]][s[i].q[h][1] + dy[(d + 3) % 4]] == '.')
					d = (d + 3) % 4;//左拐
				else
					continue;//不动
				s[i].head = (h + 100004) % 100005;
				s[i].tail = (t + 100004) % 100005;
				s[i].q[s[i].head][0] = s[i].q[h][0] + dx[d];
				s[i].q[s[i].head][1] = s[i].q[h][1] + dy[d];
				way[s[i].q[h][0]][s[i].q[h][1]] = i + 'a';
				way[s[i].q[s[i].head][0]][s[i].q[s[i].head][1]] = i + 'A';
				way[s[i].q[t][0]][s[i].q[t][1]] = '.';
				s[i].dir = d;
				move = 1;
			}
		if (!move) break;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%c", way[i][j]);
		printf("\n");
	}
	return 0;
}
