#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define fst first
#define snd second
using namespace std;

struct node {
	int setv, sumv;
	node(): sumv(0), setv(0) {}
};

int n, m, _n, id[50005];
pair<int, int> a[50005], b[50005];
node* tree;

void init() {
	_n = 1;
	while (_n <= n + 1) _n <<= 1;
	tree = new node[_n << 1];
}

inline void flag(int k, int v) { tree[k].setv = v; }

inline void update(int k, int l, int r, int a, int b, int v) {
	int lt = k << 1, rt = (k << 1) + 1;
	if (a <= l && r <= b)
		flag(k, v);
	else {
		int mid = (l + r) >> 1;
		if (a <= mid) update(lt, l, mid, a, b, v); 
		if (mid < b) update(rt, mid + 1, r, a, b, v);
	}
}

inline int query(int k, int l, int r, int a, int b) {
	if (r < a || l > b) return 0;//or INF, -INF
	if (tree[k].setv) return tree[k].setv;
	if (a <= l && r <= b) { return 0; }
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	return query(lt, l, mid, a, b) + query(rt, mid + 1, r, a, b);
}

int main() {
	cin >> n; init();
	int maxx = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[n - i - 1].fst);
		//a[n - i - 1].fst = i;
	}
	for (int i = 0; i < n; i++) { a[i].snd = i; b[i] = a[i]; }
	sort(b, b + n);
	id[0] = 1;
	for (int i = 1; i < n; i++) {
		if (b[i].fst == b[i - 1].fst) id[i] = id[i - 1];
		else id[i] = id[i - 1] + 1;
	}
	for (int i = 0; i < n; i++) a[b[i].snd].fst = id[i];
	for (int i = 0; i < n; i++) {
		if (a[i].fst >= maxx) {
			update(1, 0, _n - 1, maxx, a[i].fst, i + 1);
			maxx = a[i].fst + 1;
		} else {
			int en = query(1, 0, _n - 1, a[i].fst, a[i].fst);
			if (i + 1 - en > ans) ans = i + 1 - en;
		}
	}
	cout << ans << endl;
	return 0;
}