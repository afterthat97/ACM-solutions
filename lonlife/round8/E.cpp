#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;

int rec[100];
int ask[100005];

int main() {
	int T;
	cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		memset(rec, -1, sizeof rec);
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++) {
			int cnt;
			scanf("%d", &cnt);
			int x = cnt, sum = 0;
			while (x) {
				sum += x % 10;
				x /= 10;
			}
			ask[i] = rec[sum];
			rec[sum] = max(rec[sum], cnt);
		}
		printf("Case #%d:\n", idx);
		for (int i = 0; i < q; i++) {
			int p;
			scanf("%d", &p);
			printf("%d\n", ask[p]);
		}
	}
	return 0;
}
