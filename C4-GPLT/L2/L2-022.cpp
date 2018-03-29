#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct node {
	int addr, data, next;
}mem[100000];

vector<node> seq, ans;

int main() {
	int head, n; cin >> head >> n;
	for (int i = 0; i < n; i++) {
		int addr, data, next;
		scanf("%d %d %d", &addr, &data, &next);
		mem[addr].addr = addr;
		mem[addr].data = data;
		mem[addr].next = next;
	}
	int p = head;
	while (p != -1) {
		seq.push_back(mem[p]);
		p = mem[p].next;
	}
	int l = 0, r = seq.size() - 1;
	for (int odd = 0; l <= r; odd = 1 - odd) {
		if (odd)
			ans.push_back(seq[l++]);
		else
			ans.push_back(seq[r--]);
	}
	for (int i = 0; i < ans.size() - 1; i++)
		printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i+1].addr);
	printf("%05d %d -1\n", ans.back().addr, ans.back().data);
	return 0;
}
