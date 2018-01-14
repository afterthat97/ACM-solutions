#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

int a[200005], n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n / 2; i+=2) swap(a[i], a[n - i + 1]);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}