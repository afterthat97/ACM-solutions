#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define maxn 1000005
#define maxl 33
using namespace std;

struct node {
	int num, next[2];
}trie[maxn * maxl];

int tsize, x, n, ans, a[maxn];

inline void init_node(int idx) {
	memset(&trie[idx], 0, sizeof(node));
}

inline void ins(int x) {
	for (int i = 30, cnt = 0; ~i; i--) {
		int bit = (x >> i) & 1;
		if (trie[cnt].next[bit] == 0) {
			trie[cnt].next[bit] = ++tsize;
			init_node(tsize);
		}
		cnt = trie[cnt].next[bit];
		++trie[cnt].num;
	}
}

inline void del(int x) {
	for (int i = 30, cnt = 0; ~i; i--) {
		int bit = (x >> i) & 1;
		cnt = trie[cnt].next[bit];
		--trie[cnt].num;
	}
}

inline int query(int x, int f) {
	int ans = 0;
	for (int i = 30, cnt = 0; ~i; i--) {
		int bit = ((x >> i) & 1) ^ f;
		if (trie[cnt].next[bit] && trie[trie[cnt].next[bit]].num) {
			ans += bit << i;
			cnt = trie[cnt].next[bit];
		} else {
			ans += (!bit) << i;
			cnt = trie[cnt].next[!bit];
		}
	}
	return ans;
}

int main() {
	while (scanf("%d %d", &n, &x) == 2) {
		init_node(0);
		ans = tsize = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			ins(a[i]);
		}
		for (int i = 0; i < n; i++) {
			del(a[i]);
			ans = max(ans, query(a[i] ^ x, 1) ^ a[i] ^ x);
			ins(a[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
