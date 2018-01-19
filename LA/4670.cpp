#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <string>
#define maxn 155
#define maxl 75
#define maxnode maxn * maxl
#define maxw 1000010
#define sigma_size 26
using namespace std;

int size, trie[maxnode][30], f[maxnode], last[maxnode];
vector<int> flag[maxnode];
int  num[maxn];
char p[maxn][maxl], t[maxw];

inline void init() {
	memset(num, 0, sizeof num);
	memset(trie, 0, sizeof trie);
	for (int i = 0; i < maxnode; i++) flag[i].clear();
	memset(last, 0, sizeof last);
	size = 0;
}

inline int id(char ch) { return ch - 'a'; }

inline void insert(char *s, int i) {
	int p = 0, len = strlen(s);
	for (int i = 0; i < len; i++) {
		int c = id(s[i]);
		if (!trie[p][c]) trie[p][c] = ++size;
		p = trie[p][c];
	}
	flag[p].push_back(i);
}

inline void find(char* t) {
	int len = strlen(t);
	for (int i = 0, j = 0; i < len; i++) {
		int c = id(t[i]);
		if (c >= sigma_size || c < 0) { j = 0; continue; }
		j = trie[j][c];
		for (int tmp = j; tmp; tmp = last[tmp])
			for (int t = 0; t < flag[tmp].size(); t++)
				num[flag[tmp][t]]++;
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
	int n; 
	while (scanf("%d", &n) == 1 && n) {
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%s", p[i]);
			insert(p[i], i);
		}
		getf();
		scanf("%s", t);
		find(t);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (num[i] > ans) ans = num[i];
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++)
			if (num[i] == ans) printf("%s\n", p[i]);
	}
	return 0;
}