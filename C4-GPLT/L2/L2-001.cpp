#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <functional>
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;

struct edge {
	int to, cost;
	edge(int t, int c):to(t), cost(c) {}
};

vector<edge> g[MAXN];
int sp[MAXN], save[MAXN], paths[MAXN], sum[MAXN], pre[MAXN], order[MAXN];
typedef pair<int, int> node;
int np, ne, ps, pe;

void dijkstra() {
	priority_queue<node, vector<node>, greater<node> > q;
	q.push(node(0, ps));
	memset(sp, INF, sizeof sp); sp[ps] = 0; sum[ps] = save[ps]; paths[ps] = 1;

	while (!q.empty()) {
		node now = q.top(); q.pop();
		if (now.first > sp[now.second]) continue;
		int cnt = now.second;
		for (int i = 0; i < g[cnt].size(); i++)
			if (sp[cnt] + g[cnt][i].cost < sp[g[cnt][i].to]) {
				sp[g[cnt][i].to] = sp[cnt] + g[cnt][i].cost;
				paths[g[cnt][i].to] = paths[cnt];
				sum[g[cnt][i].to] = sum[cnt] + save[g[cnt][i].to];
				pre[g[cnt][i].to] = cnt;
				q.push(node(sp[g[cnt][i].to], g[cnt][i].to));
			} else if (sp[cnt] + g[cnt][i].cost == sp[g[cnt][i].to]) {
				paths[g[cnt][i].to] += paths[cnt];
				if (sum[cnt] + save[g[cnt][i].to] > sum[g[cnt][i].to]) {
					sum[g[cnt][i].to] = sum[cnt] + save[g[cnt][i].to];
					pre[g[cnt][i].to] = cnt;
				}
			}
	}
}

int main() {
	scanf("%d %d %d %d", &np, &ne, &ps, &pe);
	for (int i = 0; i < np; i++)
		scanf("%d", &save[i]);
	for (int i = 0; i < ne; i++) {
		int px, py, w;
		scanf("%d %d %d", &px, &py, &w);
		g[px].push_back(edge(py, w));
		g[py].push_back(edge(px, w));
	}

	dijkstra();

	printf("%d %d\n", paths[pe], sum[pe]);
	int cnt = 0;
	for (int i = pe; i != ps; i = pre[i])
		order[++cnt] = i;
	printf("%d", ps);
	for (int i = cnt; i > 0; i--) printf(" %d", order[i]);
	return 0;
}
