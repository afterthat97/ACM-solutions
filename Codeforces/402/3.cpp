#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node {
	int x, y;
}a[200005];

int n, k;

bool cmp(const node& a, const node& b) {
	return (a.x - a.y) < (b.x - b.y);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].x);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].y);
	sort(a, a + n, cmp);

	int ans = 0;
	for (int i = 0; i < k; i++)
		ans += a[i].x;

	for (int i = k; i < n; i++)
		if (a[i].x - a[i].y < 0)
			ans += a[i].x;
		else 
			ans += a[i].y;

	cout << ans << endl;
	return 0;
}
