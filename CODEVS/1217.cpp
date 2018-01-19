#include <iostream>
#include <stdio.h>
#define INF 0x3f3f3f3f
#define uint unsigned int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
using namespace std;

const int maxn = 1 << 21;
int a, b, v, n;
int addv[maxn], minv[maxn];

void init() {
	uint _n = 1;
	while (_n < n) _n <<= 1;
	for (uint i = _n; i < _n + n; i++) {
		scanf("%d", &addv[i]);
		minv[i] = addv[i];
	}
	for (uint i = _n + n; i < _n * 2; i++) {
		addv[i] = 0;
		minv[i] = INF;
	}
	n = _n;
	while (_n > 1) {
		_n >>= 1;
		for (int i = _n; i < 2 * _n; i++)
			minv[i] = min(minv[i << 1], minv[(i << 1) + 1]);
	}
}

inline void maintain(uint k, uint l, uint r) {
	minv[k] = 0;
	if (r > l)
		minv[k] = min(minv[k << 1], minv[(k << 1) + 1]);
	minv[k] += addv[k];
}

inline void update(uint k, uint l, uint r) {
	if (a <= l && b >= r)
		addv[k] += v;
	else {
		uint m = (r + l) / 2;
		if (a <= m) update(k << 1, l, m);
		if (b > m) update((k << 1) + 1, m + 1, r);
	}
	maintain(k, l, r);
}

int main() {
	uint m;
	scanf("%d %d", &n, &m);
	init();
	for (uint i = 0; i < m; i++) {
		scanf("%d %d %d", &v, &a, &b);
		v = -v;
		update(1, 1, n);
		if (minv[1] < 0) {
			printf("-1\n%d", i + 1);
			return 0;
		}
	}
	cout << 0;
	return 0;
}