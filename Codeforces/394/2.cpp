#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

int n, l;
int a[100], b[100];


int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < n; j++) cin >> b[j];
	for (int j = n; j < n + n; j++) b[j] = b[j - n] + l;
	
	for (int i = 0; i < n; i++) {
		int dx = b[i] - a[0];
		bool succ = 1;
		for (int j = 1; j < n; j++) {
			if (dx != b[i + j] - a[j]) succ = 0;
		}
		if (succ) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}