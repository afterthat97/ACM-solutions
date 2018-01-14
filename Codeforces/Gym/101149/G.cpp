#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> info;
info we[200005], you[200005];
int n, m, ans[200005];

bool cmp(const info& a, const info& b) {
	return a.fst > b.fst;
}

int main() {
	multiset<info> s;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &we[i].fst, &we[i].snd);
	cin >> m;
	for (int i = 0; i < m; i++)
		scanf("%d %d", &you[i].fst, &you[i].snd);
	sort(we, we + n, cmp);
	sort(you, you + m, cmp);
	int dead = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m && you[j].fst >= we[i].fst) {
			s.insert(info(you[j].snd, j + 1)); j++;
		}
		if (s.empty()) { dead = 1; break; }
		multiset<info>::iterator it = s.lower_bound(info(we[i].snd, 0));
		if (it == s.end()) { dead = 1; break; }
		ans[i] = it -> second;
		s.erase(it);
	}
	if (dead) puts("-1");
	else {
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
	}

	return 0;
}
