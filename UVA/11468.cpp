#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#define maxn 22
#define maxl 22
#define maxnode maxn * maxl
#define sigma_size 62
using namespace std;

int size, n, k, trie[maxnode][70], f[maxnode];
double prob[70], d[maxnode][105];
bool flag[maxn * maxl], vis[maxnode][105];
char p[maxl];

inline void init() {
	memset(prob, 0, sizeof prob);
	memset(trie, 0, sizeof trie);
	memset(flag, 0, sizeof flag);
	memset(vis, 0, sizeof vis);
	memset(d, 0, sizeof d);
	size = 0;
}

inline int idx(char ch) {
	if (ch <= '9') return ch - '0';
	if (ch <= 'Z') return ch - 'A' + 10;
	return ch - 'a' + 36;
}

inline void insert(char *s) {
	int p = 0, len = strlen(s);
	for (int i = 0; i < len; i++) {
		int c = idx(s[i]);
		if (!trie[p][c]) trie[p][c] = ++size;
		p = trie[p][c];
	}
	flag[p] = 1;
}

void getf() {
	queue<int> q;
	memset(f, 0, sizeof f);
	for (int c = 0; c < sigma_size; c++)
		if (trie[0][c]) q.push(trie[0][c]);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int c = 0; c < sigma_size; c++) {
			int u = trie[now][c];
			if (u == 0) { trie[now][c] = trie[f[now]][c]; continue; }
			q.push(u);
			int j = f[now];
			while (j && trie[j][c] == 0) j = f[j];
			f[u] = trie[j][c];
			flag[u] |= flag[f[u]];
		}
	}
}

double work(int now, int l) {
	if (l == 0) return 1.0;
	if (vis[now][l]) return d[now][l];
	d[now][l] = 0;
	for (int i = 0; i < sigma_size; i++)
		if (!flag[trie[now][i]])
			d[now][l] += prob[i] * work(trie[now][i], l - 1);
	vis[now][l] = 1;
	return d[now][l];
}

int main() {
	int T; scanf("%d", &T);
	for (int cnt = 1; cnt <= T; cnt++) {
		init(); scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", p); insert(p);
		}
		getf();
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			double tmp; char s[2];
			scanf("%s %lf", s, &tmp);
			prob[idx(s[0])] = tmp;
		}
		int l; scanf("%d", &l);
		printf("Case #%d: %.6lf\n", cnt, work(0, l));
	}
	return 0;
}