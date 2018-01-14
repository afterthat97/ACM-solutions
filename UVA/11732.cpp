#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#define maxn 4005
#define ll long long
#define maxl 1005
using namespace std;

inline int f(char ch) {
	if (ch <= '9') return ch - '0';
	if (ch <= 'Z') return ch - 'A' + 10;
	return ch - 'a' + 36;
}

int trie[maxn * maxl][70], size, n;
int flag[maxn * maxl], val[maxn * maxl];

int insert(char* s) {
	int p = 0, len = strlen(s), pass = 0;
	for (int i = 0; i < len; i++) {
		int c = f(s[i]);
		pass += val[trie[p][c]];
		if (!trie[p][c]) {
			trie[p][c] = ++size;
			val[size] = 1;
		} else
			val[trie[p][c]]++;
		p = trie[p][c];
	}
	flag[p]++;
	return (pass << 1) + flag[p] - 1;
}

int main() {
	char s[maxl]; int idx = 0; ll ans = 0;
	while (scanf("%d", &n) && n) {
		memset(trie, 0, sizeof trie); 
		memset(flag, 0, sizeof flag);
		memset(val, 0, sizeof val);
		ans = size = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			ans += insert(s) + i;
		}
		printf("Case %d: %lld\n", ++idx, ans);
	}
    return 0;
}
