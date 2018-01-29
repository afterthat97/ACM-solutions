#include <iostream>
#include <stdio.h>
#define maxn 100005
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> point;
point a[maxn];
int n, id1, id2;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].fst, &a[i].snd);
		if (a[i].fst < a[id1].fst) id1 = i;
	}
	long long kx = 1, ky = 0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		if (i == id1) continue;
		long long dx = a[i].fst - a[id1].fst;
		long long dy = a[i].snd - a[id1].snd;
		if (dx == 0) { id2 = i; break; }
		if (dx * ky > dy * kx) { id2 = i; kx = dx; ky = dy; }
	}
	cout << id1 + 1 << ' ' << id2 + 1 << endl;
	return 0;
}
