#include <iostream>
#include <stdio.h>
using namespace std;

int n;
struct node {
	int val, nxt, head;
	node(int v = 0, int n = 0): val(v), nxt(n) { head = -1; }
}a[100000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int addr, val, nxt;
		scanf("%d %d %d", &addr, &val, &nxt);
		a[addr].val = val; a[addr].nxt = nxt;
		if (a[addr].head == -1) a[addr].head = 1;
		a[nxt].head = 0;
	}
	for (int i = 0; i < 100000; i++)
		if (a[i].head == 1) {
			int p = a[i].nxt;
			printf("%d", a[i].val);
			while (~p) {
				printf(" %d", a[p].val);
				p = a[p].nxt;
			}
			putchar('\n');
		}
	return 0;
}