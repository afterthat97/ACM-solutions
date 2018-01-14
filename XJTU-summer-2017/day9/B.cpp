#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 35
using namespace std;

int succ, n, m, ans, p[maxn][maxn], st, des, pnum[maxn];

#define mod1 1000003
#define mod2 1009
#define hash1(x) ((x & 0x7fffffff) % mod1)
#define hash2(x) ((x & 0x7fffffff) % mod2)
int h[mod1], v[mod1];

inline void insert(int x) {
	int idx, h1 = hash1(x), h2 = hash2(x);
	for (int i = 0;; i++) {
		idx = (h1 + i * h2) % mod1;
		if (h[idx] == x || h[idx] == -1) break;
	}
	h[idx] = x; v[idx]++;
}

inline int query(int x) {
	int idx, h1 = hash1(x), h2 = hash2(x);
	for (int i = 0;; i++) {
		idx = (h1 + i * h2) % mod1;
		if (h[idx] == -1) return 0;
		if (h[idx] == x) return v[idx];
	}
}

int main() {
	scanf("%d", &n);
	while (scanf("%d", &n) == 1) {
		succ = st = des = ans = 0;
		memset(p, 0, sizeof p);
		memset(h, -1, sizeof h);
		memset(v, 0, sizeof v);
		for (int i = 1, base = 1; i <= n; i++) {
			char ch[1]; scanf("%s", ch);
			if (ch[0] == 'b') st += base; base <<= 1;
		}
		for (int i = 1, base = 1; i <= n; i++) {
			char ch[1]; scanf("%s", ch);
			if (ch[0] == 'b') des += base; base <<= 1;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int x, y; scanf("%d %d", &x, &y); p[x][y] = 1;
		}
		for (int i = 1; i <= n; i++) {
			int num = 0;
			for (int k = 1, base = 1; k <= n; k++) {
				num += p[i][k] * base; base <<= 1;
			}
			pnum[i] = num ^ (1 << (i - 1));
		}
		int mid = n / 2, fst = 1, snd = 1;//[1, mid], [mid + 1, n]
		for (int i = 0; i < mid; i++) fst <<= 1;
		for (int i = 0; i < n - mid; i++) snd <<= 1;
		for (int i = 0; i < fst; i++) {
			ans = 0;
			for (int cnt = 1, tmp = i; cnt <= mid; tmp >>= 1, cnt++)
				if (tmp & 1) ans ^= pnum[cnt];
			insert(ans);
		}
		int succ = 0;
		for (int i = 0; i < snd; i++) {
			ans = st;
			for (int cnt = mid + 1, tmp = i; cnt <= n; tmp >>= 1, cnt++)
				if (tmp & 1) ans ^= pnum[cnt];
			succ += query(ans ^ des); 
		}
		if (succ) printf("%d\n", succ); else puts("poor plasterer");
	}
	return 0;
}
