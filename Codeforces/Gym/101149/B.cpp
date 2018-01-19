#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define fst first
#define snd second
using namespace std;

typedef pair<long long, long long> node;
node a[200005];
int n;

bool cmp(const node& a, const node& b) {
	return (a.fst - a.snd) < (b.fst - b.snd);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &a[i].fst, &a[i].snd);
	
	sort(a, a + n, cmp);

	long long ans = a[0].fst;
	for (int i = 1; i < n; i++) {
		ans = max(ans + a[i].snd, a[i].fst);
	}
	cout << ans << endl;
	return 0;
}
