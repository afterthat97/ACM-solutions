#include <iostream>
using namespace std;

int a[1005], n, m;

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 0; i < m; i++) scanf("%d", &a[i]);
		bool succ = 1;
		for (int i = 1; i < n; i++) {
			int start, t = 0; scanf("%d", &start);
			if (start == a[0])
				for (int i = 1; i < m; i++) {
					scanf("%d", &t);
					if (t != a[i]) { succ = 0; }
				}
			else
				for (int i = 1; i < m; i++) {
					scanf("%d", &t);
					if (t == a[i]) { succ = 0; }
				}
		}
		puts(succ ? "Yes" : "No");
	}
	return 0;
}
