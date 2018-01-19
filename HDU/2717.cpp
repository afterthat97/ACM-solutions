#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>
using namespace std;

int step[100005], st, ed;

int bfs() {
	memset(step, 0x3f, sizeof step);
	queue<int> q;
	q.push(st);
	step[st] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == ed) return step[now];
		if (now < 100000 && step[now + 1] > step[now] + 1) {
			step[now + 1] = step[now] + 1;
			q.push(now + 1);
		}
		if (now > 0 && step[now - 1] > step[now] + 1) {
			step[now - 1] = step[now] + 1;
			q.push(now - 1);
		}
		if ((now << 1) <= 100000 && step[now << 1] > step[now] + 1) {
			step[now << 1] = step[now] + 1;
			q.push(now << 1);
		}
	}
	return -1;
}

int main() {
	while (scanf("%d %d", &st, &ed) == 2) {
		printf("%d\n", bfs());
	}
	return 0;
}
