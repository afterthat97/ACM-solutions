#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int cnta, cntb;

int main() {
	int a, b;
	cin >> a >> b;
	for (int i = 1; a - i >= 0; i += 2) {
		a -= i; 
		cnta++;
	}
	for (int i = 2; b - i >= 0; i += 2) {
		b -= i;
		cntb++;
	}
	puts(cnta > cntb ? "Valera" : "Vladik");

	return 0;
}
