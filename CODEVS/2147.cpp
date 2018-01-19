#include <iostream>
#include <cstring>
#include <stdio.h>
#define INF 0x7fffffff
#define ll long long
using namespace std;

const int maxh = 10000003;

int h[maxh], m, n, t;

inline int hash1(int x) {
	return (x & 0x7fffffff) % maxh;
}

inline int hash2(int x) {
	return (x & 0x7fffffff) % 1009;
}

void ins(int x) {
	int i = 1, idx;
	for (;; i++) {
		idx = (hash1(x) + i*hash2(x)) % maxh;
		if (h[idx] == x) {
			putchar('1');
			return;
		}
		if (h[idx] == INF) {
			putchar('0');
			h[idx] = x;
			return;
		}
		if (idx == (hash1(x) + hash2(x)) % maxh && i > 1) {
			while (1) {
				idx = (idx + 1) % maxh;
				if (h[idx] == x) {
					putchar('1');
					return;
				}
				if (h[idx] == INF) {
					putchar('0');
					h[idx] = x;
					return;
				}
			}
		}
	}
}
/*
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
}*/

int main() {
	for (int i = 0; i < maxh; i++)
		h[i] = INF;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		ins(t);
	}
	return 0;
}