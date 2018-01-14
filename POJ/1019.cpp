#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#define ll long long
using namespace std;

ll sumlen[100000];
char str[500000];

inline ll getlen(int idx) {
	if (idx < 10) {
		return idx;
	} else if (idx < 100) {
		return 9 + (idx - 9) * 2;
	} else if (idx < 1000) {
		return 9 + 90 * 2 + (idx - 99) * 3;
	} else if (idx < 10000) {
		return 9 + 90 * 2 + 900 * 3 + (idx - 999) * 4;
	} else { // idx < 100000
		return 9 + 90 * 2 + 900 * 3 + 9000 * 4 + (idx - 9999) * 5;
	}
}

int main() {
	ll T, k = 0; cin >> T;
	for (int i = 1; i < 100000; i++)
		sumlen[i] = getlen(i);
	for (int i = 2; i < 100000; i++)
		sumlen[i] += sumlen[i - 1];
	while (T--) {
		cin >> k;
		int idx = lower_bound(sumlen, sumlen + 100000, k) - sumlen;
		stringstream stream;
		for (int i = 1; i <= idx; i++)
			stream << i;
		putchar(stream.str()[k - sumlen[idx - 1] - 1]);
		putchar('\n');
	}
	return 0;
}
