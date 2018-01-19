#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

ll n;

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 1000; j++) {
			ll rest = n - 1234567 * i - 123456 * j;
			if (rest >= 0 && rest % 1234 == 0) {
				puts("YES");
				return 0;
			}	
		}
	puts("NO");
	return 0;
}