#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define gcd __gcd
#define maxp 300005
#define maxn 300005
#define ll long long
#define pi acos(-1.0)
using namespace std;

struct comp {
	double re, im;
	comp(double r = 0, double i = 0) : re(r), im(i) {}
	comp operator + (comp x) { return comp(re + x.re, im + x.im); }
	comp operator - (comp x) { return comp(re - x.re, im - x.im); }
	comp operator * (comp x) { return comp(re * x.re - im * x.im, re * x.im + im * x.re); }
};

int g[maxp];
inline void FFT(comp* a, int n, int f) {
	g[0] = 0; int t = -1;
	for (int _n = 1; _n < n; _n <<= 1) t++;
	for (int i = 1; i < n; i++) {
		g[i] = (g[i >> 1] >> 1) | ((i & 1) << t);
		if (g[i] > i) swap(a[i], a[g[i]]);
	}
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

bool hasroot[maxn], notp[maxn];
int pnum, p[maxn], phi[maxn];

void init(int n) {
	pnum = 0;
	for (int i = 2; i < n; i++) {
		if (!notp[i]) {
			p[pnum++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < pnum && i * p[j] < n; j++) {
			int k = i * p[j]; notp[k] = 1;
			if (i % p[j] == 0) {
				phi[k] = phi[i] * p[j];
				break;
			}
			phi[k] = phi[i] * (p[j] - 1);
		}
	}
	hasroot[1] = hasroot[2] = hasroot[4] = 1;
	for (int i = 1; i < pnum; i++) {
		for (ll j = p[i]; j < maxn; j *= p[i])
			hasroot[j] = 1;
		for (ll j = p[i] << 1; j < maxn; j *= p[i])
			hasroot[j] = 1;
	}
}

inline ll qpow(ll a, ll k, ll MOD) {
	ll ans = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
	}
	return ans;
}

int minroot(int n) {
	if (n < 3) return 1;
	if (!hasroot[n]) return -1;
	int fac[100], fnum = 0, x = phi[n];
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) {
			fac[fnum++] = i;
			while (x % i == 0) x /= i;
		}
	if (x != 1) fac[fnum++] = x;
	for (int a = 1; a < n; a++) {
		if (gcd(a, n) != 1) continue;
		bool succ = 1;
		for (int k = 0; k < fnum; k++)
			if (qpow(a, phi[n] / fac[k], n) == 1) {
				succ = 0; break;
			}
		if (succ) return a;	
	}
	return -1;
}

void allroot(int n, int& rnum, int* r) {
	int minr = minroot(n); rnum = 0;
	r[rnum++] = minr;
	if (minr == -1) return;
	for (int d = 2; d < phi[n]; d++)
		if (gcd(d, phi[n]) == 1)
			r[rnum++] = qpow(minr, d, n);
}

int r[maxp], rr[maxp], n, m;
ll ans[maxp], num[maxp];
comp tmpa[maxp], tmpb[maxp];

int main() {
	int T; cin >> T;
	r[0] = 1; init(maxn);
	while (T--) {
		memset(num, 0, sizeof num);
		memset(rr, 0, sizeof rr);
		scanf("%d %d", &n, &m);
		int root = minroot(m), p = m, n0 = 0;
		for (int i = 1; i < p; i++) {
			r[i] = (r[i - 1] * root) % p;
			rr[r[i]] = i;
		}
		for (int i = 0; i < n; i++) {
			int t; scanf("%d", &t); t %= p;
			if (t) num[rr[t]]++; else n0++;
		}
		int k = 1; while (k < p * 2) k <<= 1;
		for (int i = 0; i < p; i++) tmpa[i] = tmpb[i] = comp(num[i], 0);
		for (int i = p; i < k; i++) tmpa[i] = tmpb[i] = comp(0, 0);
		FFT(tmpa, k, 1);
		FFT(tmpb, k, 1);
		for (int i = 0; i < k; i++) tmpa[i] = tmpa[i] * tmpb[i];
		FFT(tmpa, k, -1);
		for (int i = 0; i < k; i++) ans[i] = tmpa[i].re + 0.01;
		for (int i = 1; i < p; i++) ans[i * 2] -= num[i] * num[i];
		for (int i = 1; i < k; i++) ans[i] /= 2;
		for (int i = 1; i < p; i++) ans[i * 2] += num[i] * (num[i] - 1) / 2;
		for (int i = p; i < k; i++) ans[i - (p - 1)] += ans[i];
		printf("%lld\n", (ll)n0 * (n - 1) - (ll)n0 * (n0 - 1) / 2);
		for (int i = 1; i < p; i++) printf("%lld\n", ans[rr[i]]);
	}
    return 0;
}

