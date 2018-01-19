#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int opt[10], num[10], n, N, ans;
char str[30];

int main() {
	cin >> n >> N;
	for (int i = 0; i < n; i++) cin >> num[i];
	int s = 1; for (int i = 0; i < n - 1; i++) s *= 3;
	for (int i = 0; i < s; i++) {
		memset(opt, 0, sizeof opt);//0: combine, 1: '+', 2: '-'
		for (int cnt = 0, tmp = i; tmp > 0; tmp /= 3) 
			opt[cnt++] = tmp % 3;
		for (int k = 0, cnt = 0; k < n; k++) {
			str[cnt++] = num[k] + '0';
			if (k == n - 1) { str[cnt] = 0; break; }
			if (opt[k] == 1)
				str[cnt++] = '+';
			else if (opt[k] == 2)
				str[cnt++] = '-';
		}
		char *p = str; int sum = 0;
		sscanf(p, "%d", &sum);
		for (int t = 0; *p; p++) {
			while (*p >= '0' && *p <= '9') p++;
			if (*p == 0) break;
			sscanf(p, "%d", &t); sum += t;
		}
		if (sum == N) ans++;
	}
	cout << ans << endl;
	return 0;
}
