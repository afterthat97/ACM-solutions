#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

struct point {
	int x, y;
	point(int x = 0, int y = 0):x(x), y(y) {}
}p[2510];

point operator  - (const point& a, const point& b) {
	return point(a.x - b.x, a.y - b.y);
};

point blk[700][4], dir;
int n, m, np, nb, ps, pe, idx, h[60], v[60];
bool g[2600][2600];
double sp[2600];
typedef pair<double, int> P;

inline int dcmp(int x) { if (x < 0) return -1; else return x > 0; }
inline int cross(point a, point b) { 
	return dcmp(ll(a.x) * ll(b.y) - ll(a.y) * ll(b.x)); 
}
inline bool inter(point a1, point a2, point b1, point b2) {
	int c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1),
		c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
	return c1*c2 < 0 && c3*c4 < 0;
}
inline double len(int i, int j) {
	return sqrt(ll(p[j].x - p[i].x)*ll(p[j].x - p[i].x) 
			+ ll(p[j].y - p[i].y)*ll(p[j].y - p[i].y));
}
inline void dijkstra() {
	priority_queue<P, vector<P>, greater<P> > q;
	for (int i = 0; i < np; i++) sp[i] = (i == ps ? 0 : INF);
	q.push(P(0, ps));
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int v = p.second;
		if (sp[v] < p.first) continue;
		for (int i = 0; i < np; i++)
			if (g[v][i]) {
				double len12 = len(v, i);
				if (sp[v] + len12 < sp[i]) {
					sp[i] = sp[v] + len12;
					q.push(P(sp[i], i));
				}
			}
	}
}

int main() {
	while (scanf("%d %d", &n, &m) == 2 && n && m) {
		memset(g, 0, sizeof(g));
		np = nb = 0;
		ps = 4 * m * n; pe = 4 * m * n + 1;
		scanf("%d %d %d %d", &p[ps].x, &p[ps].y, &p[pe].x, &p[pe].y);
		for (int i = 1; i <= 2 * n; i++) scanf("%d", &h[i]);
		for (int i = 1; i <= 2 * m; i++) scanf("%d", &v[i]);
		for (int i = 1; i <= 2 * m; i++)
			for (int j = 1; j <= 2 * n; j++)
				p[np++] = point(v[i], h[j]);
		np += 2;
		dir = p[pe] - p[ps];
		h[0] = v[0] = -100005; h[2 * n + 1] = v[2 * m + 1] = 100005;
		for (int i = 0; i <= 2 * n; i += 2)
			for (int j = 0; j <= 2 * m; j += 2) {
				blk[nb][0] = point(v[i], h[j]);
				blk[nb][1] = point(v[i], h[j + 1]);
				blk[nb][2] = point(v[i + 1], h[j + 1]);
				blk[nb][3] = point(v[i + 1], h[j]);
				nb++;
			}
		int dx = dcmp(dir.x), dy = dcmp(dir.y);
		for (int i = 0; i < np; i++)
			for (int j = 0; j < np; j++)
				if (!g[i][j]) {
					if (dx * (p[j] - p[i]).x < 0 && dy * (p[j] - p[i]).y < 0)
						continue;
					if ((p[i].x == p[j].x || p[i].y == p[j].y) 
							&& (i < np - 2) && (j < np - 2)) {
						g[i][j] = g[j][i] = 1;
						continue;
					}
					bool succ = 1;
					for (int k = 0; k < nb; k++) {
						if (blk[k][0].x >= p[i].x && blk[k][0].x >= p[j].x) 
							continue;
						if (blk[k][2].x <= p[i].x && blk[k][2].x <= p[j].x) 
							continue;
						if (blk[k][0].y >= p[i].y && blk[k][0].y >= p[j].y) 
							continue;
						if (blk[k][2].y <= p[i].y && blk[k][2].y <= p[j].y) 
							continue;
						if (inter(blk[k][3], blk[k][1], p[i], p[j]) 
							|| inter(blk[k][2], blk[k][0], p[i], p[j])) {
							succ = 0;
							break;
						}
					}
					if (succ) g[j][i] = g[i][j] = 1;
				}
		dijkstra();
		printf("Case %d: %.4f\n", ++idx, sp[pe]);
	}
	return 0;
}
