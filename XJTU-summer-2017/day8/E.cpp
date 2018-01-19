#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#define maxn 1
#define maxl 1000010
#define maxw 1000010
#define LETTER 26
using namespace std;

struct node {
	int len, num, fail, match, next[LETTER];
}pool[maxn * maxl];

node* const trie = pool + 1;
int tsize, n, flag[maxw];
char w[maxw], t[maxl];

inline void init() {
	tsize = 0;
	memset(pool, 0, 2 * sizeof(node));
	memset(flag, 0, sizeof flag);
	trie[0].fail = -1;
}

inline int convert(char ch) { return ch - 'a'; }
inline char convert2(int x) { return x + 'a'; }

inline void ins(const char *s) {
	int cnt = 0;
    for (int i = 0; s[i]; i++) {
		int &pos = trie[cnt].next[convert(s[i])];
		if (pos == 0) {
			pos = ++tsize;
			memset(&trie[tsize], 0, sizeof(node));
		}
		cnt = pos;
		trie[cnt].len = i + 1;
    }
	++trie[cnt].num;
}

inline void build() {
	queue<int> q; q.push(0);
	while (!q.empty()) {
		int cnt = q.front(); q.pop();
		for (int i = 0; i < LETTER; i++) {
			int &pos = trie[cnt].next[i];
			if (pos) {
				q.push(pos);
				trie[pos].fail = trie[trie[cnt].fail].next[i];
				trie[pos].match = trie[pos].num ? pos : trie[trie[pos].fail].match;
			} else pos = trie[trie[cnt].fail].next[i];
		}
	}
}

inline int query(const char* s) {
	for (int i = 0, cnt = 0; s[i]; i++) {
		cnt = trie[cnt].next[convert(s[i])];
		int tmp = trie[cnt].match;
		flag[i - trie[tmp].len + 1]++;
		flag[i + 1]--;
	}
	for (int i = 1; s[i]; i++)
		flag[i] += flag[i - 1];
}

int main() {
	while (scanf("%d", &n) == 1) {
        init();
        for (int i = 0; i < n; i++) {
            scanf("%s", t);
            ins(t);
        }
        scanf("%s", w);
		build();
		query(w);
		for (int i = 0; w[i]; i++)
			putchar(flag[i] ? '*' : w[i]);
		putchar('\n');
    }
    return 0;
}
