#include <iostream>
#include <stdio.h>
using namespace std;

int n, a[25][2];

int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++)
			scanf("%d %d", &a[i][0], &a[i][1]);
		int num = 1, ans = 0; 
		for (int i = 0; i < n; i++) num <<= 1;
		for (int i = 0; i < num; i++) {
			int nx = 0, ny = 0;
			for (int tmp = i, cnt = 0; cnt < n; tmp >>= 1) {
				if (tmp & 1) {
					nx += a[cnt][0];
					ny += a[cnt][1]; 
				}
				cnt++;
			}
			if (nx < 0 || ny < 0) continue;
			if (nx * nx + ny * ny > ans)
				ans = nx * nx + ny * ny;
		}
		printf("%d\n", ans);
	}
	return 0;
}
