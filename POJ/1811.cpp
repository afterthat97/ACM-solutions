#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define ll long long
using namespace std;

ll mul(ll a, ll b, ll mod) {
	ll ans = 0;
    while (b) {
        if (b & 1) { 
            ans += a;
            if (ans >= mod) ans -= mod;
        }
        a <<= 1;
        if (a >= mod) a -= mod; 
        b >>= 1;
    }  
    return ans;  
}  

ll qpow(ll a, ll k, ll mod) {
	ll ans = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = mul(ans, a, mod);
		a = mul(a, a, mod);
	}
	return ans;
}

bool test(ll a, ll n) {
	if (n <= 1 || (n & 1) == 0) return 0;
	ll d = n - 1;
	while ((d & 1) == 0) d >>= 1;
	ll t = qpow(a, d, n);
	if (t == 1 || t == n - 1) return 1;
	while (d < n - 1) {
		t = mul(t, t, n);
		if (t == n - 1) return 1;
		d <<= 1;
	}
	return 0;
}

const ll lowp[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool prime(ll n) {
	for (int i = 0; i < 12; i++) {
		if (n == lowp[i]) return 1;
		if (!test(lowp[i], n)) return 0;
	}
	return 1;
}

ll gcd(ll a, ll b) {
	if (a == 0) return 1;
	if (a < 0) return gcd(-a, b);
	while (b) {
		ll tmp = a % b;
		a = b; b = tmp;
	}
	return a;
}

ll Pollard_rho(ll x, ll c) {
    ll i = 1, k = 2, x0 = rand() % x;
	ll y = x0;
    while (1) {
        i++;  
        x0 = (mul(x0, x0, x) + c) % x;  
        ll d = gcd(y - x0, x);  
        if (d != 1 && d != x) return d;  
        if (y == x0) return x;
        if (i == k) { y = x0; k += k; }  
    }
}  

ll factor[100], tot;

void Findfac(ll n) {
	if (prime(n)) { 
        factor[tot++] = n;  
        return;  
    }  
    ll p = n;
    while (p >= n)
		p = Pollard_rho(p, rand() % (n - 1) + 1);  
    Findfac(p);  
    Findfac(n / p);  
}

int main() {
	int T; cin >> T;
	while (T--) {
		ll n; cin >> n;
		if (prime(n)) { puts("Prime"); continue; }
		tot = 0; Findfac(n);
		ll ans = factor[0];
		for (int i = 1; i < tot; i++)
			ans = min(ans, factor[i]);
		printf("%lld\n", ans);
	}
	return 0;
}
