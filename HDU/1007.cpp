#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <float.h>
#include <cmath>
#define inf DBL_MAX
#define fst first
#define snd second
#define maxn 100005
using namespace std;

typedef pair<double, double> point;

bool cmp_y(const point& a, const point& b) {
	return a.snd < b.snd;
}

double dis(const point& a, const point& b) {
	double dx = a.fst - b.fst;
	double dy = a.snd - b.snd;
	return sqrt(dx * dx + dy * dy);
}

point tmp[maxn];

double solve(point* a, int n) {
	if (n == 1) return inf;
	int mid = n / 2, cnt = 0;
	double x = a[mid].fst;
	double d = min(solve(a, mid), solve(a + mid, n - mid));
	inplace_merge(a, a + mid, a + n, cmp_y);
	for (int i = 0; i < n; i++)
		if (fabs(a[i].fst - x) < d) {
			for (int j = max(0, cnt - 7); j < cnt; j++)
				d = min(d, dis(a[i], tmp[j]));
			tmp[cnt++] = a[i];
		}
	return d;
}

point a[maxn];

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &a[i].fst, &a[i].snd);
		sort(a, a + n);
		printf("%.2f\n", solve(a, n) / 2);
	}
	return 0;
}
