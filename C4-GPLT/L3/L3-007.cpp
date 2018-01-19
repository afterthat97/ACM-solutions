#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
#define sec second
#define fst first
using namespace std;

struct edge {
	int to, cost[2], next;
	edge(int t = 0, int c1 = 0, int c2 = 0, int n = 0):
		to(t), next(n) {
		cost[0] = c1; cost[1] = c2;
	}
}g[500005];

int gsize, np, ne, ps, pe;
int sp[505], pre[505], head[505], dis[505], way[2][505];
typedef pair<int, int> node;

inline void add_edge(int px, int py, int c1, int c2) {
	g[gsize] = edge(py, c1, c2, head[px]);
	head[px] = gsize++;
}

void dijkstra(bool idx) {
	priority_queue<node, vector<node>, greater<node> > q;
	memset(sp, INF, sizeof sp); sp[ps] = 0;
	memset(dis, INF, sizeof dis); dis[ps] = 0;
	q.push(node(0, ps));
	while (!q.empty()) {
		node now = q.top(); q.pop();
		if (sp[now.sec] < now.fst) continue;
		for (int cnt = now.sec, i = head[now.sec]; ~i; i = g[i].next)
			if (sp[g[i].to] > sp[cnt] + g[i].cost[idx]) {
				sp[g[i].to] = sp[cnt] + g[i].cost[idx];
				pre[g[i].to] = cnt;
				dis[g[i].to] = dis[cnt] + (idx ? 1 : g[i].cost[!idx]);
				q.push(node(sp[g[i].to], g[i].to));
			} else if (sp[g[i].to] == sp[cnt] + g[i].cost[idx]
				&& dis[cnt] + (idx ? 1 : g[i].cost[!idx]) < dis[g[i].to]) {
				pre[g[i].to] = cnt;
				dis[g[i].to] = dis[cnt] + (idx ? 1 : g[i].cost[!idx]);
				q.push(node(sp[g[i].to], g[i].to));
			}
	}
}

int main() {
	memset(head, -1, sizeof head);
	scanf("%d %d", &np, &ne);
	for (int i = 0; i < ne; i++) {
		int px, py, one_way, len, time;
		scanf("%d %d %d %d %d", &px, &py, &one_way, &len, &time);
		add_edge(px, py, time, len);
		if (!one_way) add_edge(py, px, time, len);
	}
	scanf("%d %d", &ps, &pe);
	int ans[2];
	for (int idx = 0; idx < 2; idx++) {
		dijkstra(idx);
		for (int p = pe; p != ps; p = pre[p]) way[idx][++way[idx][0]] = p;
		ans[idx] = sp[pe];
	}
	bool same = (way[0][0] == way[1][0]);
	for (int i = 1; i <= way[0][0]; i++)
		if (way[0][i] != way[1][i]) same = 0;
	if (same) {
		printf("Time = %d; Distance = %d: %d", ans[0], ans[1], ps);
		for (int i = way[0][0]; i > 0; i--) printf(" => %d", way[0][i]);
	} else {
		printf("Time = %d: %d", ans[0], ps);
		for (int i = way[0][0]; i > 0; i--) printf(" => %d", way[0][i]);
		printf("\nDistance = %d: %d", ans[1], ps);
		for (int i = way[1][0]; i > 0; i--) printf(" => %d", way[1][i]);
	}
	return 0;
}
