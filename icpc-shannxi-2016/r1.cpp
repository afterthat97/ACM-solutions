#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

int T;
long long a, b;

int main() {
	cin >> T;
	for (int i = 1; i < T; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ":\n" << a + b << endl;
	}
    return 0;
}
