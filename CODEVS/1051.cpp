#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int maxh = 1000003;

struct node {
	char s[60];
	int len;
	node():len(-1) {};
}h[maxh];

inline int BKDRHash(const char* s) {
	int ans = 0, len = strlen(s);
	for (int i = 0; i < len; i++)
		ans = ans * 26 + s[i] - 'a';
	return (ans & 0x7fffffff) % maxh;
}

inline void ins(const char *s, int l) {
	for (int idx = BKDRHash(s);; idx = (idx + 1) % maxh) {
		if (h[idx].len == -1) {
			strcpy(h[idx].s, s);
			h[idx].len = l;
			return;
		}
		if (strcmp(h[idx].s, s) == 0) return;
	}
}

inline int query(const char *s) {
	for (int idx = BKDRHash(s);; idx = (idx + 1) % maxh) {
		if (h[idx].len == -1) return 0;
		if (strcmp(h[idx].s, s) == 0) return h[idx].len + 1;
	}
}

int n, len, maxl, t, ans;
char s[60], raw[60];

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", raw);
		strcpy(s, raw);
		len = strlen(s);
		maxl = 0;
		for (int j = len - 1; j > 0; j--) {
			s[j] = 0;
			if ((t = query(s)) > maxl) maxl = t;
		}
		ins(raw, maxl);
		if (maxl > ans) ans = maxl;
	}
	printf("%d", ans + 1);
	return 0;
}