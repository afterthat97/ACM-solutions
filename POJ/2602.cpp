#include <stdio.h>
#include <string.h>
#include <iostream>
#define max(x, y) ((x) < (y) ? (y) : (x))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define abs(x) ((x) < 0 ? (-x) : (x))
#define maxlen 1000009
using namespace std;

class bint {
private:
	int len, s[maxlen];
	void inc() { 
		int flag = neg(); s[0] += 1; 
		for (int i = 0; i < len && s[i] == 10; s[i++] = 0) s[i + 1]++;
		if (neg() > flag) s[len++] = 0;
	}
	void dec() {
		int flag = neg(); s[0] -= 1; 
		for (int i = 0; i < len && s[i] == -1; s[i++] = 9) s[i + 1]--;
		if (neg() < flag) s[len++] = 9;
	}
	void inv() { for (int i = 0; i < len; i++) s[i] = 9 - s[i]; inc(); }
	int neg() const { return s[len - 1] > 4 ? 9 : 0; }
	void clean() { 
		while (len > 2 && s[len - 1] == 0 && s[len - 2] < 5) len--; 
		while (len > 2 && s[len - 1] == 9 && s[len - 2] > 4) len--;
	}

public:
	bint(char* raw) {
		memset(s, 0, sizeof s);
		char *str = raw[0] == '-' ? raw + 1 : raw; len = strlen(str) + 1;
		for (int i = 0; str[i]; i++) s[len - i - 2] = str[i] - '0';
		if (raw[0] == '-') inv();
	}
	bint(int v = 0) {
		memset(s, 0, sizeof s); 
		int val = abs(v); if (!val) { len = 2; return; }
		for (len = 0; val; val /= 10) s[len++] = val % 10; len++;
		if (v < 0) inv();
	}
	bint(const bint& a) { len = a.len; memcpy(s, a.s, 4 * len); }
	bint& operator = (const bint& a) { len = a.len; memcpy(s, a.s, 4 * len); return *this; }
	int to_int() {
		int ans = 0; bint tmp = *this; if (tmp.neg()) tmp.inv();
		for (int i = 0, b = 1; i < len; i++, b *= 10) ans += b * tmp.s[i];
		return neg() ? -ans : ans;
	}
	friend bint operator + (bint& a, bint& b);
	friend bint operator + (bint& a, int b);
	friend bint operator - (bint& a, bint& b);
	friend bint operator - (bint& a, int b);
	friend bint operator * (bint a, bint b);
	friend bint operator * (bint a, int b);
	friend bint operator / (bint a, bint b);
	friend bint operator / (bint a, int b);
	friend bint operator % (bint a, bint b);
	friend bint operator % (bint a, int b);
	friend bint operator << (bint& a, int k);
	friend bint operator >> (bint& a, int k);
	bint operator <<= (int k);
	bint operator >>= (int k);
	bint operator += (bint& a) 	{ *this = *this + a; return *this; }
	bint operator += (int a) 	{ *this = *this - a; return *this; }
	bint operator -= (bint& a) 	{ *this = *this - a; return *this; }
	bint operator -= (int a) 	{ *this = *this - a; return *this; }	
	bint operator *= (bint& a) 	{ *this = *this * a; return *this; }
	bint operator *= (int a)   	{ *this = *this * a; return *this; }
	bint operator /= (bint& a) 	{ *this = *this / a; return *this; }
	bint operator /= (int a) 	{ *this = *this / a; return *this; }
	bool operator < (bint& a)  	{ return (*this - a).neg() > 0; }
	bool operator < (int a)  	{ return (*this - a).neg() > 0; }
	bool operator > (bint& a)  	{ return (a - *this).neg() > 0; }
	bool operator > (int a)  	{ bint t = a; return (t - *this).neg() > 0; }
	bool operator <= (bint& a) 	{ return (a - *this).neg() <= 0; }
	bool operator <= (int a) 	{ bint t = a; return (t - *this).neg() <= 0; }
	bool operator >= (bint& a) 	{ return (*this - a).neg() <= 0; }
	bool operator >= (int a) 	{ return (*this - a).neg() <= 0; }
	bool operator == (bint& a) 	{ bint t = *this - a; return t.len < 10 && !t.to_int(); }
	bool operator == (int a) 	{ bint t = *this - a; return t.len < 10 && !t.to_int(); }
	bool operator != (bint& a) 	{ return !(*this == a); }
	bool operator != (int a) 	{ return !(*this == a); }
	bint operator ++ (int)     	{ bint tmp(*this); inc(); return tmp; }
	bint operator ++ ()			{ inc(); return *this; }
	bint operator -- (int)		{ bint tmp(*this); dec(); return tmp; }
	bint operator -- ()			{ dec(); return *this; }
	bint operator - () 			{ bint tmp(*this); tmp.inv(); return tmp; }
	friend std::ostream& operator << (std::ostream&, const bint&);
	friend std::istream& operator >> (std::istream&, bint&);
};

bint bint::operator <<= (int k) {	
	for (int i = len - 1; ~i; i--) s[i + k] = s[i];
	len += k; clean(); return *this;	
}

bint bint::operator >>= (int k) {
	for (int i = 0; i < len - k; i++) s[i] = s[i + k];
	len -= k; if (len <= 0) *this = 0; clean(); return *this;
}

bint operator + (bint& a, bint& b) {
	bint ans; ans.len = max(a.len, b.len) + 1;
	for (int i = a.len, ta = a.neg(); i < ans.len; i++) a.s[i] = ta;
	for (int i = b.len, tb = b.neg(); i < ans.len; i++) b.s[i] = tb;
	for (int i = 0; i <= a.len || i <= b.len; i++) {
		ans.s[i] += a.s[i] + b.s[i];
		if (ans.s[i] > 9) { ans.s[i] -= 10; ans.s[i + 1]++; }
	}
	ans.clean(); return ans;
}

bint operator + (bint& a, int b) { bint t = b; return a + t; }
bint operator - (bint& a, bint& b) { bint t = b; t.inv(); return a + t; }
bint operator - (bint& a, int b) { bint t = -b; return a + t; }

bint operator * (bint a, bint b) {
	if (b.len < 9) return a * b.to_int();
	bool flag = (a.neg() > 0) ^ (b.neg() > 0);
	if (a.neg()) a.inv(); if (b.neg()) b.inv();
	bint ans; ans.len = a.len + b.len + 1;
	for (int i = 0; i < a.len; i++)
		for (int j = 0; j < b.len; j++)
			ans.s[i + j] += a.s[i] * b.s[j];
	for (int i = 0; i < ans.len - 2; ans.s[i++] %= 10) 
		ans.s[i + 1] += ans.s[i] / 10;
	ans.clean(); return flag ? -ans : ans;
}

bint operator * (bint a, int b) {
	if (b > 99999999) return a * bint(b);
	bool flag = (a.neg() > 0) ^ (b < 0);
	if (a.neg()) a.inv(); if (b < 0) b = -b;
	bint ans; ans.len = a.len + 10;
	for (int i = 0; i < a.len; i++)
		ans.s[i] += a.s[i] * b;
	for (int i = 0; i < ans.len - 2; ans.s[i++] %= 10)
		ans.s[i + 1] += ans.s[i] / 10;
	ans.clean(); return flag ? -ans : ans;
}

bint operator / (bint a, bint b) {
	if (b.len < 10) return a / b.to_int();
	bool flag = (a.neg() > 0) ^ (b.neg() > 0);
	if (a.neg()) a.inv(); if (b.neg()) b.inv();
	bint ans; ans.len = a.len;
	bint mod = 0;
	for (int i = a.len - 1; ~i; i--) {
		mod <<= 1; mod.s[0] = a.s[i];
		for (; mod >= b; ans.s[i]++) mod -= b;
	}
	ans.clean(); return flag ? -ans : ans;
}

bint operator / (bint a, int b) {
	bool flag = (a.neg() > 0) ^ (b < 0);
	if (a.neg()) a.inv(); if (b < 0) b = -b;
	bint ans; ans.len = a.len;
	long long mod = 0;
	for (int i = a.len - 1; ~i; i--) {
		mod *= 10; mod += a.s[i];
		ans.s[i] = mod / b; mod %= b;
	}
	ans.clean(); return flag ? -ans : ans;
}

bint operator % (bint a, bint b) {
	if (b.len < 10) return a % b.to_int();
	bool flag = (a.neg() > 0);
	if (a.neg()) a.inv(); if (b.neg()) b.inv();
	bint ans; ans.len = a.len;
	bint mod = 0;
	for (int i = a.len - 1; ~i; i--) {
		mod <<= 1; mod.s[0] = a.s[i];
		for (; mod >= b; ans.s[i]++) mod -= b;
	}
	mod.clean(); return flag ? -mod : mod;
}

bint operator % (bint a, int b) {
	bool flag = (a.neg() > 0);
	if (a.neg()) a.inv(); if (b < 0) b = -b;
	bint ans; ans.len = a.len;
	long long mod = 0;
	for (int i = a.len - 1; ~i; i--) {
		mod *= 10; mod += a.s[i];
		ans.s[i] = mod / b; mod %= b;
	}
	return flag ? -int(mod) : int(mod);
}

bint operator << (bint& a, int k) {
	bint ans; ans.len = a.len + k;
	for (int i = 0; i < a.len; i++) ans.s[i + k] = a.s[i];
	ans.clean(); return ans;
}

bint operator >> (bint& a, int k) {
	bint ans; ans.len = a.len - k;
	for (int i = 0; i < ans.len; i++) ans.s[i] = a.s[i + k];
	if (ans.len <= 0) ans = 0; ans.clean(); return ans;
}


int n;


std::ostream& operator << (std::ostream& out, const bint& a) {
	bint tmp = a; if (a.neg()) { putchar('-'); tmp.inv(); }
	for (int i = tmp.len - 1; ~i; i--) 
		if (tmp.s[i] || i == 0) {
			int rest = n - (i + 1);
			for (int j = 0; j < rest; j++) putchar('0');
			for (int j = i; ~j; j--) putchar(tmp.s[j] + '0'); break;
		}
	return out;
}

std::istream& operator >> (std::istream& cin, bint& a) {
	char s[maxlen]; scanf("%s", s); a = bint(s);
	return cin;
}

char s1[1000009], s2[1000009];

int main() {
	cin >> n; getchar();
	for (int i = 0; i < n; i++) {
		char x, y; x = getchar(); getchar(); y = getchar(); getchar();
		s1[i] = x; s2[i] = y;
	}
	static bint a(s1), b(s2);
	cout << a + b << endl;
	return 0;
}
