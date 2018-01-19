#include <iostream>
#include <stdio.h>
using namespace std;

int n, a, len, k, num, ans[200005];
char str[200005];

int main() {
	cin >> n >> a >> len >> k;
	scanf("%s", str);
	int i = 0;
	while (i < n - len + 1 && a > 1) {
		if (str[i] == '1') {
			i++; continue;
		}
		bool succ = 1;
		for (int j = 0; j < len; j++)
			if (str[i + j] == '1') {
				i += j + 1; succ = 0; break;
			}
		if (!succ) continue;
		a--; i += len;
	}
	while (i < n - len + 1) {
		if (str[i] == '1') {
			i++; continue;
		}
		bool succ = 1;
		for (int j = 0; j < len; j++)
			if (str[i + j] == '1') {
				i += j + 1; succ = 0; break;
			}
		if (!succ) continue;
		i += len - 1;
		str[i] = '1';
		ans[num++] = i + 1;
	}
	
	printf("%d\n%d", num, ans[0]);
	for (int i = 1; i < num; i++)
		printf(" %d", ans[i]);

	return 0;
}
