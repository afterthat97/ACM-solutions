#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char ch; double l;
		cin >> ch >> l;
		if (ch == 'M') l /= 1.09;
		else l *= 1.09;
		printf("%.2f\n", l);
	}
	return 0;
}
