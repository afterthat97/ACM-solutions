#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

int g[20][20];

int main() {
	int T;
	cin >> T;
	for (int idx = 0; idx < T; idx++) {
		int a = 0, b = 0;
		for (int i = 1; i < 20; i++)
			for (int j = 1; j < 20; j++) {
				char x; cin >> x;
				if (x == '0') a++; 
				if (x == '1') b++;
			}
		printf("Case #%d:\n", idx + 1);
		if (a > b) puts("White");
		else if (b > a) puts("Black");
		else puts("Equal");
	}
    return 0;
}
