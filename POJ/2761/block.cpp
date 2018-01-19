#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxn 100005
#define bsize 4000
using namespace std;

int n, m, a[maxn], sort_a[maxn];
int bkt[maxn / bsize + 10][bsize + 10];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0, cnt = 0; i < n; i++) {
		scanf("%d", &a[i]);
		bkt[i / bsize][cnt++] = a[i];
		if (cnt == bsize) cnt = 0;
		sort_a[i] = a[i];
	}
	sort(sort_a, sort_a + n);
	for (int i = 0; i < n / bsize; i++)
		sort(bkt[i], bkt[i] + bsize);
	for (int i = 0; i < m; i++) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k); l--;
		int lb = -1, ub = n - 1;
		while (ub - lb > 1) {
			int mid = (ub + lb) >> 1;
			int x = sort_a[mid], tl = l, tr = r, c = 0;
			while (tl < tr && tl % bsize)
				if (a[tl++] <= x) ++c;
			while (tl < tr && tr % bsize)
				if (a[--tr] <= x) ++c;
			while (tl < tr) {
				int now = tl / bsize;
				c += upper_bound(bkt[now], bkt[now] + bsize, x) - bkt[now];
				tl += bsize;
			}
			if (c >= k) ub = mid;
			else lb = mid;
		}
		printf("%d\n", sort_a[ub]);
	}

	return 0;
}
