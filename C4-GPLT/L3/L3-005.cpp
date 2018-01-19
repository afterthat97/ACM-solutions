#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f
using namespace std;

int np, np1, np2, ne, w, head[1050], gsize, sp[1050];
typedef pair<int, int> node;
struct edge {
	int to, cost, next;
	edge(int t = 0, int c = 0, int n = 0): to(t), cost(c), next(n) {}
}g[20050];

inline void add_edge(int px, int py, int d) {
	g[gsize] = edge(py, d, head[px]);
	head[px] = gsize++;
}

void dijkstra(int ps) {
	priority_queue<node, vector<node>, greater<node> > q;
	memset(sp, INF, sizeof sp); sp[ps] = 0;
	q.push(node(0, ps));
	while (!q.empty()) {
		node p = q.top(); q.pop();
		if (sp[p.second] < p.first) continue;
		for (int cnt = p.second, i = head[p.second]; ~i; i = g[i].next)
			if (sp[g[i].to] > sp[cnt] + g[i].cost) {
				sp[g[i].to] = sp[cnt] + g[i].cost;
				q.push(node(sp[g[i].to], g[i].to));
			}
	}
}

int main() {
	memset(head, -1, sizeof head);
	scanf("%d %d %d %d", &np1, &np2, &ne, &w);
	np = np1 + np2;
	for (int i = 0; i < ne; i++) {
		char s1[10], s2[10]; int px, py, dis;
		scanf("%s %s %d", s1, s2, &dis);
		if (s1[0] == 'G') {
			sscanf(s1, "G%d", &px); px += np1;
		} else sscanf(s1, "%d", &px);
		if (s2[0] == 'G') {
			sscanf(s2, "G%d", &py); py += np1;
		} else sscanf(s2, "%d", &py);
		add_edge(px, py, dis);
		add_edge(py, px, dis);
	}

	int ansv = -1, ansd = -1, ans_sum = 0;
	for (int i = np1 + 1; i <= np1 + np2; i++) {
		dijkstra(i);
		int minv = INF, sumv = 0, maxv = -1;
		for (int i = 1; i <= np1; i++) {
			sumv += sp[i];
			if (sp[i] < minv) minv = sp[i];
			if (sp[i] > maxv) maxv = sp[i];
		}
		if (maxv > w) continue;
		if ((minv > ansv) || (minv == ansv && sumv < ans_sum)) {
			ansv = minv; ansd = i - np1; ans_sum = sumv;
		}
	}
	if (ansv == -1) printf("No Solution");
	else printf("G%d\n%.1lf %.1lf", ansd, ansv * 1.0, (ans_sum * 1.0) / np1 + 1e-8);
	return 0;
}
