#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <cstring>
#define MAXN 10005
#define MAXM 50005
using namespace std;

struct edge {
	int to;
	int next;
	bool passed;
}g[MAXM * 2];

int np, ne, head[MAXN], cnt;
stack<int> way;

void dfs(int now) {
	for (int i = head[now]; ~i; i = g[i].next)
		if (!g[i].passed) {
			g[i].passed = true;
			dfs(g[i].to);
		}
	way.push(now);
}

int main() {
	scanf("%d %d", &np, &ne);
	memset(head, -1, sizeof head);
	for (int i = 0; i < ne; i++) {
		int px, py;
		scanf("%d %d", &px, &py);
		g[cnt].to = py;
		g[cnt].next = head[px];
		g[cnt].passed = false;
		head[px] = cnt;
		cnt++;
		g[cnt].to = px;
		g[cnt].next = head[py];
		g[cnt].passed = false;
		head[py] = cnt;
		cnt++;
	}

	dfs(1);
	while (!way.empty()) {
		printf("%d\n", way.top());
		way.pop();
	}
	return 0;
}
