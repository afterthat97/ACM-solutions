#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <vector>
#include <ctime>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <memory>
#include <numeric>
#include <utility>

#define INF 999999999
#define uint unsigned int
#define uchar unsigned char
#define ll long long
#define ull unsigned long long
#define pause cin.get();cin.get();
#define read(i) scanf("%d", &i);
#define ln printf("\n");
using namespace std;

struct node {
	int x, y;
}a[505];

bool cmp(const node& a, const node& b) {
	if (a.x < b.x) return 1;
	if (a.x > b.x) return 0;
	return a.y < b.y;
}

int n, m;

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 0; i < m; i++)
			scanf("%d %d", &a[i].x, &a[i].y);
		sort(a, a + m, cmp);
		int ans = n + 1;
		if (m > 0) {
			int l = a[0].x, r = a[0].y;
			for (int i = 1; i < m; i++) {
				if (a[i].x <= r)
					r = max(r, a[i].y);
				else {
					ans += (r - l) * 2;
					l = a[i].x;
					r = a[i].y;
				}
			}
			ans += (r - l) * 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}