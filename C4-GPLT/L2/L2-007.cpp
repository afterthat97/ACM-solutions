#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int par[10000], ans;
bool exist[10000];
double num[10000], area[10000];
struct fam {
	int id, n;
	double avg_num, avg_area;
}a[10000];

inline int getfa(int x) { return (x == par[x] ? x : getfa(par[x])); }
inline void combine(int x, int y) { par[x] = par[y] = par[getfa(x)] = getfa(y); }

bool cmp(const fam& a, const fam& b) {
	if (fabs(a.avg_area - b.avg_area) > 1e-8) return a.avg_area > b.avg_area;
	else return a.id < b.id;
}

int main() {
	for (int i = 0; i < 10000; i++) par[i] = i;
	int T; scanf("%d", &T);
	for (int idx = 0; idx < T; idx++) {
		int id, p1, p2, k, ch;
		scanf("%d %d %d %d", &id, &p1, &p2, &k);
		if (~p1) { combine(id, p1); exist[p1] = 1; }
		if (~p2) { combine(id, p2); exist[p2] = 1; }
		for (int j = 0; j < k; j++) {
			scanf("%d", &ch);
			exist[ch] = 1;
			combine(ch, id);
		}
		exist[id] = 1;
		scanf("%lf %lf", &num[id], &area[id]);
	}

	for (int i = 0; i < 10000; i++)
		if (exist[i]) {
			int bel = getfa(i);
			if (a[bel].n == 0) a[bel].id = 10000;
			if (i < a[bel].id) a[bel].id = i;
			a[bel].avg_num = (a[bel].n * a[bel].avg_num + num[i]) / (a[bel].n + 1);
			a[bel].avg_area = (a[bel].n * a[bel].avg_area + area[i]) / (a[bel].n + 1);
			a[bel].n++;
		}
	for (int i = 0; i < 10000; i++)
		if (a[i].n) ans++;
	printf("%d\n", ans);
	sort(a, a + 10000, cmp);
	for (int i = 0; i < ans; i++)
		printf("%04d %d %.3lf %.3lf\n", a[i].id, a[i].n, a[i].avg_num, a[i].avg_area);
	return 0;
}
