#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 1000005
#define INF 0x3f3f3f3f
using namespace std;

int n, m, _n, _m, q, xx[maxn], yy[maxn];
int *treex, *treey;

void init() {
	_n = 1; _m = 1;
	while (_n < n) _n <<= 1;
	while (_m < m) _m <<= 1;
	treex = new int[_n << 1];
	treey = new int[_m << 1];
}

inline void updatex(int k, int v) {
	int kk = k + _n - 1;
	while (kk > 0) {
		treex[kk] += v;
		kk >>= 1;
	}
}

int queryx(int k, int l, int r, int a, int b) {
	if (r < a || l > b) return 0;
	if (a <= l && r <= b) return treex[k];
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	return queryx(lt, l, mid, a, b) + queryx(rt, mid + 1, r, a, b);
}

inline void updatey(int k, int v) {
	int kk = k + _n - 1;
	while (kk > 0) {
		treey[kk] += v;
		kk >>= 1;
	}
}

int queryy(int k, int l, int r, int a, int b) {
	if (r < a || l > b) return 0;
	if (a <= l && r <= b) return treey[k];
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	return queryy(lt, l, mid, a, b) + queryy(rt, mid + 1, r, a, b);
}

int main() {
	int cho, x, y, x1, x2, y1, y2;
	scanf("%d %d %d", &n, &m, &q); init();
	for (int i = 0; i < q; i++) {
		scanf("%d", &cho);
		if (cho == 1) {
			scanf("%d", &x);
			if (xx[x] == 0) { 
				xx[x] = 1; updatex(x, 1); 
			} else {
				xx[x] = 0; updatex(x, -1);
			}
		} else if (cho == 2) {
			scanf("%d", &y);
			if (yy[y] == 0) { 
				yy[y] = 1; updatey(y, 1); 
			} else {
				yy[y] = 0; updatey(y, -1);
			}
		} else {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			long long sumx = queryx(1, 1, _n, x1, x2);
			long long sumy = queryy(1, 1, _n, y1, y2);
			long long ans = sumx * (y2 - y1 + 1) + sumy * (x2 - x1 + 1)
						- sumx * sumy * 2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
