//HDU 3065
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#define maxn 10005
#define maxl 55
#define maxw 1000010
#define maxnode maxn * maxl
#define sigma_size 26
using namespace std;

int size, trie[maxnode][sigma_size], f[maxnode], last[maxnode], flag[maxnode];
int num[maxnode], appear[maxnode], ans;
char p[maxn][maxl], t[maxw];

inline void init() {
    memset(num, 0, sizeof num);
    memset(trie, 0, sizeof trie);
    memset(last, 0, sizeof last);
    memset(flag, 0, sizeof flag);
	memset(appear, 0, sizeof appear);
    size = 0;
}

inline int idx(char ch) { return ch - 'a'; }

inline void insert(char *s, int i) {
    int p = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        int c = idx(s[i]);
        if (!trie[p][c]) trie[p][c] = ++size;
        p = trie[p][c];
    }
    flag[p]++;
}

inline void find(char* t) {
    int len = strlen(t);
    for (int i = 0, j = 0; i < len; i++) {
        int c = idx(t[i]);
        if (c >= sigma_size || c < 0) { j = 0; continue; }
        j = trie[j][c];
        for (int tmp = j; tmp; tmp = last[tmp]) appear[tmp] = 1;
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
			last[u] = flag[f[u]] ? f[u] : last[f[u]];
        }
    }
}

int main() {
    int n, T; cin >> T;
	while (T--) {
		scanf("%d\n", &n);
        init();
        for (int i = 1; i <= n; i++) {
            gets(p[i]);
            insert(p[i], i);
        }
        getf(); gets(t); find(t);
		int ans = 0;
		for (int i = 0; i <= size; i++)
			if (appear[i])
				ans += flag[i];
		printf("%d\n", ans);
    }
    return 0;
}
