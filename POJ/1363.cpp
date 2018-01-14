#include <iostream>
#include <stdio.h>
#include <stack>
#define read(i) scanf("%d", &i);
#define ln printf("\n");
using namespace std;

int n, from[1005], to[1005];
stack<int> c;

int main() {
	while (1) {
		read(n);
		if (n == 0) break;

		while (1) {
			int temp;
			read(temp);
			if (temp == 0) break;
			to[0] = temp;
			from[0] = 1;
			for (int i = 1; i < n; i++) {
				read(temp);
				to[i] = temp;
				from[i] = i + 1;
			}
			int pf = 0; int pt = 0;
			while (!c.empty())c.pop();
			c.push(from[pf]);
			pf++;
			while (pf <= n || pt == n) {
				if (c.empty()) {
					if (pf == n)break;
					c.push(from[pf]);
					pf++;
				} else if (c.top() == to[pt]) {
					c.pop();
					pt++;
				} else {
					if (pf == n)break;
					c.push(from[pf]);
					pf++;
				}
			}
			if (pt == n)
				printf("Yes\n");
			else
				printf("No\n");
		}
		ln;
	}
	return 0;
}
