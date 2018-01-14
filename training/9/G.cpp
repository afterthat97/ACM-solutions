#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int y[64], f[64], b[64];

void bin(ll a) {
	int cnt = 0;
	while (a > 0) {
		y[cnt++] = a & 1;
		a >>= 1;
	}
}

void binu(unsigned ll a) {
	int cnt = 0;
	while (a > 0) {
		y[cnt++] = a & 1;
		a >>= 1;
	}
}

void output(int *a) {
	int out[16] = {};
	for (int i = 0; i < 16; i++) {
		int k = 0;
		for (int j = 0, base = 1; j < 4; j++, base <<= 1)
			k += a[i * 4 + j] * base;
		out[15 - i] = k;
	}
	printf("0x");
	for (int i = 0; i < 16; i++)
		if (out[i] == 15)
			putchar('f');
		else if (out[i] == 14)
			putchar('e');
		else if (out[i] == 13)
			putchar('d');
		else if (out[i] == 12)
			putchar('c');
		else if (out[i] == 11)
			putchar('b');
		else if (out[i] == 10)
			putchar('a');
		else 
			printf("%d", out[i]);
	putchar('\n');
}			

int main() {
	ll a; char s[100]; unsigned ll au;
	while (scanf("%s", s) == 1) {
		if (s[0] != '-') sscanf(s, "%llu", &au);
		else sscanf(s, "%lld", &a);
		memset(y, 0, sizeof y);
		memset(f, 0, sizeof f);
		memset(b, 0, sizeof b);
		if (s[0] != '-') {
			binu(au);
			for (int i = 0; i < 64; i++)
				f[i] = b[i] = y[i];
		} else {
			a = -a;
			bin(a);
			f[63] = b[63] = y[63] = 1;
			for (int i = 0; i < 63; i++)
				b[i] = f[i] = 1 - y[i];
			int i = 0; b[0] += 1;
			while (b[i] > 1) {
				b[i + 1]++; b[i] = 0; i++;
			}
		}
		output(y);
		output(f);
		output(b);
	}
	return 0;
}