#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#define maxn 1
#define maxl 205
#define LETTER 26
#define ull unsigned long long
using namespace std;

struct node {
	bool flag;
	int num, val, fail, match, next[LETTER];
}pool[maxn * maxl];

struct matrix {
	int n;
	vector<ull> dat;
	matrix(const int _n): n(_n) {
		dat.resize(n * n);
		fill(dat.begin(), dat.end(), 0);
	}
	ull* operator[](const int i) { return &dat[i * n]; }
};

node* const trie = pool + 1;
int tsize, n, v[maxl];
ull ans, len;
char t[maxl];

inline void init() {
	ans = tsize = 0;
	memset(pool, 0, 2 * sizeof(node));
	trie[0].fail = -1;
}

inline int convert(char ch) { return ch - 'a'; }
inline char convert2(int x) { return x + 'a'; }

inline void ins(const char *s, int v) {
	int cnt = 0;
    for (int i = 0; s[i]; i++) {
		int &pos = trie[cnt].next[convert(s[i])];
		if (pos == 0) {
			pos = ++tsize;
			memset(&trie[tsize], 0, sizeof(node));
		}
		cnt = pos;
    }
	++trie[cnt].num;
	trie[cnt].val += v;
}

inline void build(matrix& g) {
	queue<int> q; q.push(0);
	while (!q.empty()) {
		int cnt = q.front(); q.pop();
		for (int i = 0; i < LETTER; i++) {
			int &pos = trie[cnt].next[i];
			if (pos) {
				q.push(pos);
				trie[pos].fail = trie[trie[cnt].fail].next[i];
				trie[pos].match = trie[pos].num ? pos : trie[trie[pos].fail].match;
				if (trie[pos].num) {
					int pre = trie[trie[pos].fail].match;
					trie[pos].val += trie[pre].val;
				} else
					trie[pos].val += trie[trie[pos].match].val;
			} else pos = trie[trie[cnt].fail].next[i];
			g[cnt][pos] = trie[pos].val + 1;
		}
	}
}

inline matrix work(matrix& a, matrix& b) {
	matrix ans(a.n);
	for (int i = 0; i <= tsize; i++)
		for (int k = 0; k <= tsize; k++)
			for (int j = 0; j <= tsize; j++)
				if (a[i][k] && b[k][j] && a[i][k] + b[k][j] > ans[i][j])
					ans[i][j] = a[i][k] + b[k][j];
	return ans;
}

int main() {
	while (scanf("%d %llu", &n, &len) == 2) {
        init();
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
        for (int i = 0; i < n; i++) {
            scanf("%s", t);
            ins(t, v[i]);
        }
		matrix g(tsize + 1), res(tsize + 1);
		build(g);
		for (int i = 0; i <= tsize; i++)
			for (int j = 0; j <= tsize; j++)
				res[i][j] = g[i][j];
		for (ull k = len - 1; k; k >>= 1) {
			if (k & 1) res = work(res, g);
			g = work(g, g);
		}
		for (int i = 0; i <= tsize; i++)
			if (res[0][i] > ans) ans = res[0][i];
		printf("%llu\n", ans - len);
    }
    return 0;
}
