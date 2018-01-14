#include <iostream>
#include <stdio.h>
#include <complex.h>
#include <math.h>
#define pi M_PI
using namespace std;

struct comp {
	double re, im;
	comp(double r = 0, double i = 0): re(r), im(i) {}
	comp operator + (comp x) { return comp(re + x.re, im + x.im); }
	comp operator - (comp x) { return comp(re - x.re, im - x.im); }
	comp operator * (comp x) { 
		return comp(re * x.re - im * x.im, re * x.im + im * x.re); 
	}
};

void FFT(comp* a, int* g, int n, int f) {
	for (int i = 0; i < n; i++)
		if (g[i] > i) swap(a[i], a[g[i]]);
	for (int i = 1; i < n; i <<= 1) {
		comp wn1(cos(pi / i), f * sin(pi / i));
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

void mul(comp* a, comp* b, comp* ans, int n) {
	int _n = 1, t = -1;
	while (_n < n) { _n <<= 1; t++; }
	int* g = new int[_n]; g[0] = 0;
	for (int i = 1; i < _n; i++)
		g[i] = (g[i >> 1] >> 1) | ((i & 1) << t);
	//for (int i = 0; i < _n; i++) cout << real(a[i]) << ' '; cout << endl;
	//for (int i = 0; i < _n; i++) cout << real(b[i]) << ' '; cout << endl;
	//for (int i = 0; i < _n; i++) cout << g[i] << ' '; cout << endl;
	FFT(a, g, _n, 1); FFT(b, g, _n, 1);
	//for (int i = 0; i < _n; i++) cout << real(a[i]) << ' '; cout << endl;
	//for (int i = 0; i < _n; i++) cout << real(b[i]) << ' '; cout << endl;
	for (int i = 0; i < _n; i++) ans[i] = a[i] * b[i];
	FFT(ans, g, _n, -1);
	//for (int i = 0; i < _n; i++) cout << real(ans[i]) << ' '; cout << endl;
}

#define maxn 300000

comp a[maxn], b[maxn], c[maxn << 1];
int n, n1, n2, ans[maxn << 1];

int main() {
	for (char ch = getchar(); ch >= '0'; ch = getchar())
		a[n1++] = comp(ch - '0', 0);
	for (int i = 0; i < (n1 >> 1); i++) swap(a[i], a[n1 - i - 1]);
	for (char ch = getchar(); ch >= '0'; ch = getchar())
		b[n2++] = comp(ch - '0', 0);
	for (int i = 0; i < (n2 >> 1); i++) swap(b[i], b[n2 - i - 1]);
	n = max(n1, n2); n <<= 1;
	mul(a, b, c, n);
	for (int i = 0; i < n; i++) ans[i] = c[i].re + 0.01;
	for (int i = 0; i < n; i++) 
		if (ans[i] >= 10) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
	for (int i = n - 1; ~i; i--)
		if (ans[i]) { 
			for (int j = i; ~j; j--) putchar(ans[j] + '0');
			break;
		}
	return 0;
}
