#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 4005
#define maxl 105
#define maxw 300005
#define LETTER 26
using namespace std;

struct node {
	int num, next[LETTER];
}trie[maxn * maxl];

int tsize, ans[maxw], n;
char w[maxw], t[maxl];

inline void init() {
	tsize = 0;
	memset(&trie[0], 0, sizeof(node));
}

inline int convert(char ch) {
	return ch - 'a';
}

inline void ins(const char* s) {
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
}

inline int query(const char* s) {
	int cnt = 0;
	for (int i = 0; s[i]; i++) {
		cnt = trie[cnt].next[convert(s[i])];
		if (cnt == 0) return 0; // Not found
	}
	return trie[cnt].num;
}

inline void del(const char* s) {
	int cnt = 0;
	for (int i = 0; s[i]; i++)
		cnt = trie[cnt].next[convert(s[i])];
	--trie[cnt].num;
}

int main() {
    int idx = 0;
    while (scanf("%s", w) == 1) {
		init();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", t);
            ins(t);
        }
        int len = strlen(w); ans[len] = 1;
        for (int i = len - 1; ~i; i--) {
			ans[i] = 0;
			for (int j = i, cnt = 0; w[j]; j++) {
				cnt = trie[cnt].next[convert(w[j])];
				if (cnt == 0) break;
				if (trie[cnt].num)
					ans[i] = (ans[i] + ans[j + 1]) % 20071027;
			}
        }
        printf("Case %d: %d\n", ++idx, ans[0]);
    }
    return 0;
}
