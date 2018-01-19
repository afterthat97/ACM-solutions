#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

char str[100];
int d[100], depth, stack[100];

bool check(char ch) {
	for (int i = 0; i < depth; i++)
		if (d[i] == ch) return 0;
	return 1;
}

int main() {
	int T; cin >> T;
	while (T--) {
		int l, err = 0, ans = 0, out = 0;
		depth = 0;
		cin >> l >> str;
		if (str[2] == 'n')
			sscanf(str, "O(n^%d)", &out);
		for (int i = 0; i < l; i++) {
			char opt, var, x[10], y[10];
			cin >> opt;
			if (opt == 'F') {
				cin >> var >> x >> y;
				d[depth] = var;
				if (!check(var)) err = 1;
				if (x[0] == 'n' && y[0] == 'n') stack[depth++] = 0;
				else if (x[0] == 'n' && y[0] != 'n') stack[depth++] = -1;
				else if (x[0] != 'n' && y[0] == 'n') stack[depth++] = 1;
				else {
					int vx, vy;
					sscanf(x, "%d", &vx); 
					sscanf(y, "%d", &vy);
					if (vx <= vy) stack[depth++] = 0; else stack[depth++] = -1;
				}
			} else {
				if (depth == 0) { err = 1; continue; }
				int tot = 0;
				for (int i = 0; i < depth; i++)
					if (stack[i] != -1)
						tot += stack[i];
					else break;
					ans = max(ans, tot);
				depth--;
			}
		}
		if (depth > 0) err = 1;
		if (err) puts("ERR");
		else puts(out == ans ? "Yes" : "No");
	}
	return 0;
}
