#include <iostream>
#include <stdio.h>
#define maxn 100000
using namespace std;

bool succ, f[maxn], ask[maxn];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k, id; cin >> k;
		if (k == 1) { cin >> k; continue; }
		for (int j = 0; j < k; j++) {  
			cin >> id; f[id] = 1;
		}
	}
	int m, i; cin >> m;
	for (i = 0; i < m; i++) {
		int id; cin >> id;
		if (!f[id]) {
			ask[id] = 1;
			printf("%05d", id);
			succ = 1;
			i++;
			break;
		}
	}
	for (; i < m; i++) {
		int id; cin >> id;
		if (!ask[id]) {
			ask[id] = 1;
			if (!f[id]) printf(" %05d", id), succ = 1;
		}
	}
	if (!succ) cout << "No one is handsome";
	return 0;

}
