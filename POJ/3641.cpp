#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#define ull unsigned long long
using namespace std;

int p, a;

ull q_pow(ull a, ull k) {//快速幂，a^k
	if (k == 0)
		return 1;
	ull t = q_pow(a, k >> 1);
	t = (t*t) % p;
	if (k & 1)
		return (t*a) % p;
	else
		return t;
}

bool prime(int x) {
	int t = int(sqrt(x));
	for (int i = 2; i <= t + 1; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	while (scanf("%d%d", &p, &a) == 2 && p && a) {
		if (prime(p)) {//先判断是不是素数
			printf("no\n");
			continue;
		}
		if (q_pow(a, p) == a)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}