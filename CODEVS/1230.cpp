#include <iostream>
#include <cstring>
#include <stdio.h>
#define ll long long
using namespace std;

const int maxh = 1000003;

int h[maxh], m, n, t;

inline int hash1(int x) {
	return x % maxh;
}

inline int hash2(int x) {
	return x % 1009;
}

void ins(int x) {
	int i = 1, idx;
	for (;; i++) {
		if (i > 1000) exit(EXIT_FAILURE);
		idx = (hash1(x) + i*hash2(x)) % maxh;
		if (h[idx] == x || h[idx] == -1) break;
		if (idx == (hash1(x) + hash2(x)) % maxh && i > 1) {
			while (h[idx] != -1) idx = (idx + 1) % maxh;
			break;
		}
	}
	h[idx] = x;
}

bool query(int x) {
	int i = 1, idx;
	for (;; i++) {
		idx = (hash1(x) + i*hash2(x)) % maxh;
		if (h[idx] == -1) return false;
		if (h[idx] == x) return true;
		if (idx == (hash1(x) + hash2(x)) % maxh && i > 1)
			for (;; idx = (idx + 1) % maxh) {
				if (h[idx] == -1) return false;
				if (h[idx] == x) return true;
			}
	}
}

int main() {
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	memset(h, -1, sizeof(h));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		ins(t);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		puts(query(t) ? "YES" : "NO");
	}
	return 0;
}