#include <stdio.h>
#include <cstring>
#define uint unsigned int
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1 << 18;//262144
uint n,m, a, b;
int tree[maxn];

void init() {
	uint _n = 1;
	while (_n < n) _n <<= 1;
	memset(tree, INF, sizeof(tree));
	for (uint i = _n; i < _n + n; i++)
		scanf("%d", &tree[i]);
	n = _n;
	while (_n > 1) {
		_n >>= 1;
		for (uint i = _n; i < _n * 2; i++)
			tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

void update(uint k, int a) {
	k += n - 1;
	tree[k] += a;
	while (k > 1) {
		k >>= 1;
		tree[k] = tree[2 * k] + tree[2 * k + 1];
	}
}

int query(uint k, uint l, uint r) {
	if (r < a || l > b) return 0;
	if (r <= b && l >= a) return tree[k];
	uint mid = (l + r) >> 1;
	int ql = query(2 * k, l, mid);
	int qr = query(2 * k + 1, mid + 1, r);
	return ql + qr;
}

int main() {
	scanf("%d", &n);
	init();
	scanf("%d", &m);
	for (uint i = 0; i < m; i++) {
		int id;
		scanf("%d %d %d", &id, &a, &b);
		if (id == 1)//a += b
			update(a, b);
		else
			printf("%d\n", query(1, 1, n));
	}
	return 0;
}