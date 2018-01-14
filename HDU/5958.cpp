#include <iostream>
#include <stdio.h>
#include <math.h>
#define pi acos(-1.0)
#define maxp 300005
using namespace std;

struct comp {
	double re, im;
	comp(double r = 0, double i = 0) : re(r), im(i) {}
	comp operator + (comp x) { return comp(re + x.re, im + x.im); }
	comp operator - (comp x) { return comp(re - x.re, im - x.im); }
	comp operator * (comp x) { return comp(re * x.re - im * x.im, re * x.im + im * x.re); }
};

int g[maxp];
double cospi[maxp], sinpi[maxp];

inline void FFT(comp* a, int n, int f) {
	g[0] = 0; int t = -1;
	for (int _n = 1; _n < n; _n <<= 1) t++;
	for (int i = 1; i < n; i++) {
		g[i] = (g[i >> 1] >> 1) | ((i & 1) << t);
		if (g[i] > i) swap(a[i], a[g[i]]);
	}
	for (int i = 1; i < n; i <<= 1) {
		comp wn1(cospi[i], f * sinpi[i]);
		for (int j = 0; j < n; j += (i << 1)) {
			comp wnk(1, 0);
			for (int k = 0; k < i; k++, wnk = wnk * wn1) {
				comp x = a[j + k], y = wnk * a[j + k + i];
				a[j + k] = x + y; a[j + k + i] = x - y;
			}
		}
	}
	if (!(~f)) for (int i = 0; i < n; i++) a[i].re /= n;
}

int p, r13[13], r103[103], r100003[100003], *r; 
comp a[maxp], b[maxp], tmpa[maxp], tmpb[maxp], ans[maxp];
double rhk13[13], rhk103[103], rhk100003[100003], *rhk;

void init() {
	r13[0] = r103[0] = r100003[0] = 1;
	for (int i = 1; i < maxp; i++) {
		cospi[i] = cos(pi / i); sinpi[i] = sin(pi / i);
	}
	for (int i = 0; i < 13; i++) {
		if (i) r13[i] = (r13[i - 1] << 1) % 13;
		rhk13[i] = pow(2, pow(sin(2 * pi * r13[i] / 13), 3));
	}
	for (int i = 0; i < 103; i++) {
		if (i) r103[i] = (r103[i - 1] * 5) % 103;
		rhk103[i] = pow(2, pow(sin(2 * pi * r103[i] / 103), 3));
	}
	for (int i = 0; i < 100003; i++) {
		if (i) r100003[i] = (r100003[i - 1] << 1) % 100003;
		rhk100003[i] = pow(2, pow(sin(2 * pi * r100003[i] / 100003), 3));
	}
}

int main() {
	init();
	while (scanf("%d", &p) == 1) {
		if (p == 13) {
			r = r13; rhk = rhk13;
		} else if (p == 103) {
			r = r103; rhk = rhk103;
		} else {
			r = r100003; rhk = rhk100003;
		}
		int phi = p - 1;
		for (int i = 0; i < p; i++) {
			scanf("%lf", &a[i].re);
			b[i].re = a[0].re;
			if (i) b[0].re += a[i].re;
		}
		for (int i = 0; i < phi; i++) {
			tmpa[i] = comp(a[r[phi - i - 1]].re, 0);
			tmpb[i] = comp(rhk[i], 0);
		}
		int n = 1; while (n < 2 * p) n <<= 1;
		for (int i = phi; i < n; i++) tmpa[i] = tmpb[i] = comp(0, 0);
		FFT(tmpa, n, 1); FFT(tmpb, n, 1);
		for (int i = 0; i < n; i++) ans[i] = tmpa[i] * tmpb[i];
		FFT(ans, n, -1);
		for (int i = phi; i < n; i++) ans[i % phi].re += ans[i].re;
		for (int i = 1; i < p; i++) b[r[i]].re += ans[(i - 1) % phi].re;
		for (int i = 0; i < p; i++) printf("%.3lf ", b[i].re);
		putchar('\n');
	}
	return 0;
}
