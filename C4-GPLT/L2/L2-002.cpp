#include <iostream>
#include <stdio.h>
#define abs(a) (a > 0 ? a : -a)
using namespace std;

struct node {
	int addr, val, next;
	node(int a = -1, int v = 0, int n = -1): addr(a), val(v), next(n) {}
}a[100005], a1[100005], a2[100005], p1, p2;

int head, head1 = -1, head2 = -1, n;
bool exist[100000];

void ins(node k, node& p, int &head, node* a) {
	if (head == -1) head = k.addr;
	else a[p.addr].next = k.addr;
	a[k.addr] = node(k.addr, k.val, -1);
	p = a[k.addr];
}

void output(int &head, node* a) {
	if (head == -1) return;
	for (node p = a[head];; p = a[p.next]) {
		printf("%05d %d", p.addr, p.val);
		if (p.next == -1) { printf(" -1\n"); break; } 
		else printf(" %05d\n", p.next);
	}
}

int main() {
	scanf("%d %d", &head, &n);
	for (int i = 0; i < n; i++) {
		int addr, v, next;
		scanf("%d %d %d", &addr, &v, &next);
		a[addr] = node(addr, v, next);
	}
	for (node p = a[head];; p = a[p.next]) {
		if (exist[abs(p.val)]) ins(p, p2, head2, a2);
		else ins(p, p1, head1, a1);
		exist[abs(p.val)] = 1;
		if (p.next == -1) break;
	}
	output(head1, a1); output(head2, a2);
	return 0;
}
