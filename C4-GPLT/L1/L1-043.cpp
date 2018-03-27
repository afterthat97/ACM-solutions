#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

int books[1005];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int id; char opt; int hour, min;
		double totmin = 0, times = 0;
		memset(books, -1, sizeof books);
		while (scanf("%d %c %d:%d", &id, &opt, &hour, &min) == 4) {
			if (id == 0) break;
			if (books[id] == -1) {
				if (opt == 'E') continue;
				books[id] = hour * 60 + min;
			} else {
				if (opt == 'S') {
					books[id] = hour * 60 + min;
					continue;
				}
				totmin += hour * 60 + min - books[id];
				times = times + 1;
				books[id] = -1;
			}
		}
		int avg = times > 0.5 ? totmin / times + 0.5 : 0;
		cout << times << ' ' << avg << endl;
	}
	return 0;
}
