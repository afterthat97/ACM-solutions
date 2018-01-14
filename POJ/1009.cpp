#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define maxp 1005
#define fst first
#define snd second
#define getp(idx) (point((idx) / m, (idx) % m))
#define geti(p) ((p).fst * m + (p).snd)
#define getv(idx) (val[upper_bound(st, st + cnt, (idx)) - st - 1])
using namespace std;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
typedef pair<int, int> point;
int n, m, cnt, tot, st[maxp], val[maxp];
int numres, resp[maxp << 8], resv[maxp << 8];

int main() {
	while (scanf("%d", &m) == 1 && m) {
		cnt = tot = numres = 0;
		memset(resv, 0, sizeof resv);
		memset(st, 0, sizeof st);
		memset(val, 0, sizeof val);
		while (scanf("%d %d", &val[cnt], &st[cnt + 1]) == 2 && st[cnt + 1])
			tot += st[++cnt];
		for (int i = 1; i <= cnt; i++)
			st[i] += st[i - 1];
		n = tot / m;
		st[cnt]--;
		for (int i = 0; i <= cnt; i++) {
			resp[numres++] = st[i];
			if (st[i] - m - 1 >= 0) {
				resp[numres++] = st[i] - m - 1;
				resp[numres++] = st[i] - m;
				resp[numres++] = st[i] - m + 1;
				resp[numres++] = st[i] - 1;
			}
			if (st[i] + m + 1 < tot) {
				resp[numres++] = st[i] + m + 1;
				resp[numres++] = st[i] + m;
				resp[numres++] = st[i] + m - 1;
				resp[numres++] = st[i] + 1;
			}
		}
		resp[numres++] = (n - 1) * m;
		if (n > 1) resp[numres++] = (n - 2) * m;
		sort(resp, resp + numres);
		numres = unique(resp, resp + numres) - resp;
		for (int i = 0; i < numres; i++) {
			point p = getp(resp[i]);
			for (int k = 0; k < 8; k++) {
				point t(p.fst + dx[k], p.snd + dy[k]);
				if (t.fst >= 0 && t.snd >= 0 && t.fst < n && t.snd < m)
					resv[i] = max(resv[i], abs(getv(geti(t)) - getv(geti(p))));
			}
		}
		printf("%d\n%d ", m, resv[0]);
		int b = 0;
		for (int i = 1; i < numres; i++)
			if (resv[i] != resv[i - 1]) {
				printf("%d\n%d ", resp[i] - resp[b], resv[i]);
				b = i;
			}
		printf("%d\n0 0\n", tot - resp[b]);
	}
	puts("0");
	return 0;
}
