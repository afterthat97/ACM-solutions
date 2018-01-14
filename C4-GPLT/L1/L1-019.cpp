#include <iostream>
#include <stdio.h>
using namespace std;

int n, a, b;

int main() {
	cin >> a >> b >> n;
	int aa = a, bb = b;
	for (int i = 0; i < n; i++) {
		int h1, s1, h2, s2;
		cin >> h1 >> s1 >> h2 >> s2;
		if (s1 == s2) continue;
		if (s1 == h1 + h2) a--;
		if (s2 == h1 + h2) b--;
		if (a < 0) {
			cout << "A\n" << bb - b << endl;
			return 0;
		}
		if (b < 0) {
			cout << "B\n" << aa - a << endl;
			return 0;
		}
	}
	return 0;
}
