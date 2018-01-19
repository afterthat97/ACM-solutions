#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		double h, w; cin >> h >> w;
		h -= 100;
		h *= 1.8;
		double dx = h - w;
		if (dx < 0) dx = -dx;
		if (dx < 0.1 * h)
			puts("You are wan mei!");
		else if (w < h)
			puts("You are tai shou le!");
		else 
			puts("You are tai pang le!");
	}
	return 0;
}
