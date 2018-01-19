#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#define maxn 400050
#define maxm 400050
using namespace std;

int a[maxn], sa[maxn], t[maxn], t2[maxn], c[maxm], tmp[maxn], raw[maxn], n;

void dump(int* arr, int n, string name) {
	cout << "Dump array " << name << ":\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl << endl;
}

void build_sa(int* str, int n, int m) {
	int i, *x = t, *y = t2;
	memset(c, 0, sizeof c);
	memset(sa, 0, sizeof sa);
	for (int i = 0; i < n; i++) c[x[i] = str[i]]++;
	for (int i = 1; i < m; i++) c[i] += c[i - 1];
	for (int i = n - 1;~i; i--) sa[--c[x[i]]] = i;
	for (int k = 1; k <= n; k <<= 1) {
		int p = 0;
		for (int i = n - k; i < n; i++) y[p++] = i;
		for (int i = 0; i < n; i++)
			if (sa[i] >= k) y[p++] = sa[i] - k;
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; i++) c[x[y[i]]]++;
		for (int i = 1; i < m; i++) c[i] += c[i - 1];
		for (int i = n - 1;~i; i--) sa[--c[x[y[i]]]] = y[i];
		swap(x, y); p = 1; x[sa[0]] = 0;
		for (int i = 1; i < n; i++)
			if (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k])
				x[sa[i]] = p - 1;
			else
				x[sa[i]] = p++;
		if (p >= n) break;
		m = p;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &raw[i]);
		a[i] = raw[i];
	}
	sort(raw, raw + n);
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(raw, raw + n, a[i]) - raw;
	reverse(a, a + n);
	build_sa(a, n, maxm);
	int p1 = 0, p2 = 0;
	for (int i = 0; i < n; i++) {
		p1 = sa[i];
		if (p1 > 1) break;
	}
	for (int i = 0; i < p1; i++)
		tmp[i + p1] = tmp[i] = a[i];
	build_sa(tmp, p1 << 1, maxm);
	for (int i = 0; i < p1 * 2; i++) {
		p2 = sa[i];
		if (p2 && p2 < p1) break;
	}
	p2 = p1 - p2;
	p1 = n - p1;
	p2 += p1;
	reverse(a, a + n);
	reverse(a, a + p1);
	reverse(a + p1, a + p2);
	reverse(a + p2, a + n);
	for (int i = 0; i < n; i++)
		printf("%d\n", raw[a[i]]);
	return 0;
}
