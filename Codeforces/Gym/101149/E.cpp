#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#define fst first
#define snd second
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

struct node {
	ll maxv, addv;
	node(): maxv(0), addv(0) {}
};//root from 1

int n, m, _n = 1;
node* tree;

void init() {
	while (_n < n) _n <<= 1;
	tree = new node[_n << 1];
}

inline void maintain(int k, int l, int r) {
	int lt = k << 1, rt = (k << 1) + 1;
	tree[k].maxv = 0;
	if (r > l) 
		tree[k].maxv = max(tree[lt].maxv, tree[rt].maxv);
	tree[k].maxv += tree[k].addv;
}

void update(int k, int l, int r, int a, int b, int v) {
	int lt = k << 1, rt = (k << 1) + 1;
	if (a <= l && b >= r)
		tree[k].addv += v;
	else {
		int mid = (r + l) >> 1;
		if (a <= mid) update(lt, l, mid, a, b, v);
		if (mid < b) update(rt, mid + 1, r, a, b, v);
	}
	maintain(k, l, r);
}

ll query(int k, int l, int r, int a, int b, int addv) {
	if (r < a || l > b) return -INF;
	if (a <= l && r <= b) {
		return tree[k].maxv + addv;
	} else {
		int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
		return max(query(lt, l, mid, a, b, addv + tree[k].addv)
			,query(rt, mid + 1, r, a, b, addv + tree[k].addv));
	}
}

map<int, int> f;
pair<int, int> a[200005];
int k, cnt, start, s[400005];

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a[i].fst, &a[i].snd);
		s[cnt++] = a[i].fst;
		s[cnt++] = a[i].snd;
	}
	sort(s, s + cnt);
	for (int i = 0; i < cnt; i++)
		f[s[i]] = i + 1;
	
	n = cnt + 1;
	init();
	for (int i = 0; i < k; i++) {
		a[i].fst = f[a[i].fst];
		a[i].snd = f[a[i].snd];
//		cout << a[i].fst << ' ' << a[i].snd << endl;
		update(1, 1, _n, a[i].fst, a[i].snd, 1);
		if (a[i].fst > start) start = a[i].fst;
	}
/*	cout << start << endl;
	for (int i = 0; i <= cnt + 1; i++)
		cout << query(1, 1, _n, i, i, 0) << ' ';
*/	cout << query(1, 1, _n, start, start, 0);
	return 0;
}
