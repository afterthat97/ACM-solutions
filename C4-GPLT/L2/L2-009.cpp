#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct node {
	int id, num, get;
}a[10005];

bool cmp(const node& a, const node& b) {
	if (a.get != b.get) return a.get > b.get;
	else if (a.num != b.num) return a.num > b.num;
	else return a.id < b.id;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		a[i].id = i;
		for (int j = 0; j < k; j++) {
			int p, v;
			scanf("%d %d", &p, &v);
			a[p].num++; a[p].get += v; a[i].get -= v;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		printf("%d %.2f\n", a[i].id, a[i].get / 100.0);
	}
	return 0;
}
