#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> info;
info we[100005], you[100005];
int n, m;

bool cmp1(const info& a, const info& b) {
	return a.fst > b.fst;
}

bool cmp2(const info& a, const info& b) {
	return a.snd > b.snd;
}

int main() {
	int T; cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		multiset<int> s;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d %d", &we[i].fst, &we[i].snd);
		for (int i = 0; i < m; i++)
			scanf("%d %d", &you[i].fst, &you[i].snd);
		sort(we, we + n, cmp1);
		sort(you, you + m, cmp2);
		int dead = 0;
		for (int i = 0, j = 0; j < m; j++) {
			while (i < n && we[i].fst > you[j].snd)
				s.insert(we[i++].snd);
			if (s.empty()) {
				dead = n + 1; break;
			}
			multiset<int>::iterator it = s.upper_bound(you[j].fst);
			if (it == s.end()) { dead++; it = s.begin(); }
			s.erase(it);
		}
		printf("Case #%d: %d\n", idx, n - dead);
	}

	return 0;
}
