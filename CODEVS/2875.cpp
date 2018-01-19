#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int maxh = 100003;

char h[maxh][2005];

inline int BKDRHash(const char* s) {
	int ans = 0, len = strlen(s);
	for (int i = 0; i < len; i++)
		ans = ans * 26 + s[i] - 'a';
	return (ans & 0x7fffffff) % maxh;
}

inline void ins(const char *s) {
	for (int idx = BKDRHash(s);; idx = (idx + 1) % maxh) {
		if (h[idx][0] == 0) {
			strcpy(h[idx], s);
			return;
		}
		if (strcmp(h[idx], s) == 0) return;
	}
}

inline bool query(const char *s) {
	for (int idx = BKDRHash(s);; idx = (idx + 1) % maxh) {
		if (h[idx][0] == 0) return false;
		if (strcmp(h[idx], s) == 0) return true;
	}
}

int n, m;
char s[2005];

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		ins(s);
	}
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", s);
		puts(query(s) ? "Yes" : "No");
	}
	return 0;
}