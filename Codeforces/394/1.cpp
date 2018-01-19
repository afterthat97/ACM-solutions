#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;



int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a == 0 && b == 0) {
		puts("NO");
		return 0;
	}
	if (a == b || a == b + 1 || a == b - 1) puts("YES");
	else puts("NO");

	return 0;
}