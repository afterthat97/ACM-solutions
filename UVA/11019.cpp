#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#define maxn 1005
#define maxx 105
#define maxnode maxx * maxx
#define sigma_size 123
using namespace std;

int size, n, m, x, y, trie[maxnode][sigma_size], f[maxnode], last[maxnode];
vector<int> flag[maxnode];
int cnt[maxn][maxn];
char p[maxx][maxx], t[maxn][maxn];

inline void init() {
	memset(trie, 0, sizeof trie);
	for (int i = 0; i < maxnode; i++) flag[i].clear();
	memset(cnt, 0, sizeof cnt);
	memset(last, 0, sizeof last);
	size = 0;
}

inline int idx(char ch) { return ch; }

inline void insert(char *s, int k) {
	int p = 0, len = strlen(s);
	for (int i = 0; i < len; i++) {
		int c = idx(s[i]);
		if (!trie[p][c]) trie[p][c] = ++size;
		p = trie[p][c];
	}
	flag[p].push_back(k);
}

inline void find(char* t, int k) {
	int len = strlen(t);
	for (int i = 0, j = 0; i < len; i++) {
		int c = idx(t[i]);
		if (c >= sigma_size || c < 0) { j = 0; continue; }
		j = trie[j][c];
		for (int tmp = j; tmp; tmp = last[tmp])
			for (int t = 0; t < flag[tmp].size(); t++)
				if (flag[tmp][t] <= k)
					cnt[k - flag[tmp][t]][i - y + 1]++;
	}
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
			last[u] = flag[f[u]].size() ? f[u] : last[f[u]];
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", t[i]);
		scanf("%d %d", &x, &y);
		for (int i = 0; i < x; i++) {
			scanf("%s", p[i]);
			insert(p[i], i);
		}
		getf();
		for (int i = 0; i < n; i++) find(t[i], i);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (cnt[i][j] == x) ans++;
		printf("%d\n", ans);
	}
	return 0;
}