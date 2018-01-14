#include <stdio.h>
#include <cstring>

const int maxn = 1005;
int heap[maxn], heap_size, pos[20005];

inline void up(int x) {
	int fa = x >> 1, tmp = heap[x];
	while (fa) {
		if (tmp < heap[fa]) { heap[x] = heap[fa]; } else break;
		x = fa; fa = fa >> 1;
	}
	heap[x] = tmp;
}

inline void push(int v) {
	heap[++heap_size] = v;
	up(heap_size);
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int v; scanf("%d", &v); push(v);
	}

	for (int i = 1; i <= n; i++) pos[heap[i] + 10000] = i;
	for (int i = 0; i < m; i++) {
		char s[100], s1[10], s4[10];
		gets(s);
		while (s[0] == 0) gets(s);
		sscanf(s, "%s %*s %*s %s", s1, s4);
		if (strcmp(s4, "root") == 0) {
			int v; sscanf(s1, "%d", &v);
			if (pos[v + 10000] == 1) puts("T"); else puts("F");
		} else if (strcmp(s4, "are") == 0) {
			int v1, v2; sscanf(s, "%d %*s %d", &v1, &v2);
			if (pos[v1 + 10000] / 2 == pos[v2 + 10000] / 2) puts("T"); else puts("F");
		} else if (strcmp(s4, "parent") == 0) {
			int v1, v2; sscanf(s, "%d %*s %*s %*s %*s %d", &v1, &v2);
			if (pos[v2 + 10000] / 2 == pos[v1 + 10000]) puts("T"); else puts("F");
		} else {
			int v1, v2; sscanf(s, "%d %*s %*s %*s %*s %d", &v1, &v2);
			if (pos[v1 + 10000] / 2 == pos[v2 + 10000]) puts("T"); else puts("F");
		}
	}
	return 0;
}
