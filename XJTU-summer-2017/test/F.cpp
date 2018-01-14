#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#define ll unsigned long long
using namespace std;

ll n;
char s[100];
int a[100];

int main() {
	scanf("%ull", &n);
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) 
		a[i] = s[i] - '0';

	ll b = 1, ans = 0;
	for (int i = len - 1; i >= 0;) {
		ll num = a[i], base = 10, idx = i;
		while (idx >= 1 && a[idx - 1] * base + num < n) {
			num += a[--idx] * base; 
			base *= 10; 
		}
		while (a[idx] == 0 && idx != i) idx++;
		ans += b * num; b *= n; i = idx - 1;
	}
	cout << ans << endl;
	return 0;
}
