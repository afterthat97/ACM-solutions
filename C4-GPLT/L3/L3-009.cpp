#include <stdio.h>
#define ll long long

struct point {
	ll x, y;
}now, b, watches[100005];

int n, ans;
bool can_see(const point& n, const point& b, const point&w) {
	return (w.y - b.y)*(b.x - n.x) >= (b.y - n.y)*(w.x - b.x);
}

int main() {
	scanf("%d %lld %lld %lld %lld", &n, &watches[0].x, &watches[0].y, &b.x, &b.y);
	for (int i = 2; i < n; i++) {
		scanf("%lld %lld", &now.x, &now.y);
		bool see = 0;
		for (int i = ans; i >= 0; i--)
			if (can_see(now, b, watches[i])) {//各个哨站能否看到now
				see = 1; break;
			}
		if (!see) watches[++ans] = b;//看不到now的话，就需要在b处建哨站
		b = now;
	}
	printf("%d", ans);
	return 0;
}
