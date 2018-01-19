#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#define MAXN 10000000
#define INF 0x3f3f3f3f
using namespace std;

int root;
int n, m, np, ps;
int sp1[MAXN], sp2[MAXN];
typedef pair<int, int> P;//first=distance, second=ID

struct tag_pair {
	int out;
	int value;
};

vector<tag_pair> G[MAXN];

void dijkstra1() {
	np = n + m;
	ps = root;
	priority_queue<P, vector<P>, greater<P> > q;
	memset(sp1, INF, sizeof(sp1));
	sp1[ps] = 0;

	q.push(P(0, ps));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (sp1[v] < p.first) continue;
		int siz = G[v].size();
		for (int i = 0; i<siz; i++)
			if (sp1[v] + G[v][i].value<sp1[G[v][i].out]) {
				sp1[G[v][i].out] = sp1[v] + G[v][i].value;
				q.push(P(sp1[G[v][i].out], G[v][i].out));
			}
	}
}

void dijkstra2() {
	np = n + m;
	ps = root;
	priority_queue<P, vector<P>, greater<P> > q;
	memset(sp2, INF, sizeof(sp2));
	sp2[ps] = 0;

	q.push(P(0, ps));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second;
		if (sp2[v] < p.first) continue;
		int siz = G[v].size();
		for (int i = 0; i<siz; i++)
			if (sp2[v] + G[v][i].value<sp2[G[v][i].out]) {
				sp2[G[v][i].out] = sp2[v] + G[v][i].value;
				q.push(P(sp2[G[v][i].out], G[v][i].out));
			}
	}
}

int main() {
	int T, t, num, a, tot = 0;
	tag_pair data;
	cin >> T;
	for (int Case = 1; Case <= T; Case++) {
		for (int i = 1; i <= n + m; i++) G[i].clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &t, &num);
			for (int j = 0; j<num; j++) {
				scanf("%d", &a);
				data.out = i + n;
				data.value = t;
				G[a].push_back(data);
				data.out = a;
				data.value = 0;
				G[i + n].push_back(data);
			}
		}
		root = 1;
		dijkstra1();
		root = n;
		dijkstra2();
		int ans = INF;
		for (int i = 1; i <= n; i++) {
			sp1[i] = sp1[i]<sp2[i] ? sp2[i] : sp1[i];
			if (sp1[i] < ans) ans = sp1[i];
		}
		printf("Case #%d: ", Case);
		if (ans == INF) {
			printf("Evil John\n");
			continue;
		}
		printf("%d\n", ans);
		bool first = 1;
		for (int i = 1; i <= n; i++)
			if (ans == sp1[i])
				if (first) {
					first = 0;
					printf("%d", i);
				} else {
					printf(" %d", i);
				};
		printf("\n");
	}
	return 0;
}
