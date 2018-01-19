#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>
#define pause cin.get();cin.get();
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

int n;
int f[100005], g[100005], h[100005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i]);
	int m = 0;
	for (int i = 1; i <= n; i++)
		if (g[i] == 0) {
			int x = i;
			if (f[x] != x) {
				if (f[f[x]] != f[x]) {
					cout << -1;
					return 0;
				}
				if (g[f[x]]) g[x] = g[f[x]];
				else g[x] = g[f[x]] = ++m;
			} else g[x] = ++m;
		}

	for (int i = 1; i <= n; i++)
		h[g[i]] = f[i];
	cout << m << endl;
	for (int i = 1; i <= n; i++)
		printf("%d ", g[i]);
	cout << endl;
	for (int j = 1; j <= m; j++)
		printf("%d ", h[j]);

	pause;
	return 0;
}