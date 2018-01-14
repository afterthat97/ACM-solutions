#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node {
	int val, id;
}a[100005], b[100005];

bool cmp(const node& a, const node& b) {
	return a.val < b.val;
}

int n, tree[100005], ans;

int sum(int x) {
	int ans = 0;
	for (; x > 0; x -= (x&-x))
		ans += tree[x];
	return ans;
}

void add(int x, int val) {
	for (; x <= n; x += (x&-x))
		tree[x] += val;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].val);
		a[i].id = i;
	}
	for (int j = 1; j <= n; j++) {
		scanf("%d", &b[j].val);
		b[j].id = j;
	}
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++)//i->b[i].id
		a[a[i].id].val = b[i].id;
	for (int i = 1; i <= n; i++) {
		ans = (ans + i - sum(a[i].val) - 1) % 99999997;
		add(a[i].val, 1);
	}
	printf("%d\n", ans);
	return 0;
}