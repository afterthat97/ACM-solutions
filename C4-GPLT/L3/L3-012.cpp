#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

struct line {
	int x, y1, y2;//y1 > y2
}l[10005], id[10005];

struct vec {
	int x, y;
	vec(int a = 0, int b = 0): x(a), y(b) {};
};

inline int cross(vec a, vec b) {
	ll temp = (ll)(a.x)*(ll)(b.y) - (ll)(a.y)*(ll)(b.x);
	if (temp < 0) return -1; else return temp > 0;
}

int n;
vec krmax, krmin, klmax, klmin;

inline bool cmp(line& a, line& b) { return a.x < b.x; }
inline bool cmp2(line& a, line& b) { return (a.y1 - a.y2) < (b.y1 - b.y2); }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &l[i].x, &l[i].y1, &l[i].y2);
	sort(l + 1, l + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		id[i].x = i;//x¼ÇÂ¼ÊúÏßID
		id[i].y1 = l[i].y1;
		id[i].y2 = l[i].y2;
	}
	sort(id + 1, id + n + 1, cmp2);
	for (int idx = 1; idx <= n; idx++) {
		int i = id[idx].x;
		krmax = vec(1, INF);
		krmin = vec(1, -INF);
		klmax = vec(-1, -INF);
		klmin = vec(-1, INF);
		for (int j = i + 1; j <= n; j++) {
			vec v1(l[j].x - l[i].x, l[j].y1 - l[i].y2);
			vec v2(l[j].x - l[i].x, l[j].y2 - l[i].y2);
			if (cross(krmax, v1) < 0) krmax = v1;
			if (cross(krmin, v2) > 0) krmin = v2;
		}
		for (int j = i - 1; j >= 1; j--) {
			vec v1(l[j].x - l[i].x, l[j].y1 - l[i].y2);
			vec v2(l[j].x - l[i].x, l[j].y2 - l[i].y2);
			if (cross(klmin, v1) > 0) klmin = v1;
			if (cross(klmax, v2) < 0) klmax = v2;
		}
		if (cross(krmax, krmin) > 0) continue;
		if (cross(klmax, klmin) > 0) continue;
		if (cross(krmax, klmin) < 0) continue;
		if (cross(klmax, krmin) < 0) continue;
		if (cross(klmax, krmax) * cross(klmax, krmin) <= 0)
			printf("%d %d %d %d", l[i].x + klmax.x, l[i].y2 + klmax.y, l[i].x, l[i].y2);
		else if (cross(klmin, krmax) * cross(klmin, krmin) <= 0)
			printf("%d %d %d %d", l[i].x + klmin.x, l[i].y2 + klmin.y, l[i].x, l[i].y2);
		else if (cross(klmax, krmax) > 0 && cross(klmin, krmin) < 0)
			printf("%d %d %d %d", l[i].x + krmax.x, l[i].y2 + krmax.y, l[i].x, l[i].y2);
		else if (cross(krmax, klmax) > 0 && cross(krmin, klmin) < 0)
			printf("%d %d %d %d", l[i].x + klmin.x, l[i].y2 + klmin.y, l[i].x, l[i].y2);
		break;
	}
	return 0;
}
