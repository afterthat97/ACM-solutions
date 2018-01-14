#include <stdio.h>
#include <string.h>
#include <iostream>
#define max(x, y) ((x) < (y) ? (y) : (x))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define maxlen 40000
using namespace std;

class ubint {
public:
	int len, s[maxlen];
	void clean() { 
		while (len > 1 && s[len - 1] == 0) len--;
	}
	void inc() {
		s[0]++; for (int i = 0; i < len && s[i] == 10; s[i++] = 0) s[i + 1]++;
		if (s[len]) len++;
	}
	void dec() {
		s[0]--; for (int i = 0; i < len && !(~s[i]); s[i++] = 9) s[i + 1]--;
		if (s[len - 1] == 0) len--;
	}
	int cmp(const ubint& a) {
		if (len != a.len) return len - a.len;
		for (int i = len - 1; ~i; i--)
			if (s[i] != a.s[i]) return s[i] - a.s[i];
		return 0;
	} 
public:
	ubint(char* str) {
		memset(s, 0, sizeof s); len = strlen(str);
		for (int i = 0; str[i]; i++) s[len - i - 1] = str[i] - '0';
	}
	ubint(int v = 0) {
		memset(s, 0, sizeof s);
		if (!v) { len = 1; s[0] = 0; return; }
		for (len = 0; v; v /= 10) s[len++] = v % 10;
	}
	ubint(const ubint& a) { 
		len = a.len; memcpy(s, a.s, sizeof(int) * len); clean(); 
	}
	ubint& operator = (const ubint& a) {
		len = a.len; memcpy(s, a.s, sizeof(int) * len); clean(); return *this; 
	}
	int to_int() {
		int ans = 0;
		for (int i = 0, b = 1; i < len; i++, b *= 10) ans += b * s[i];
		return ans;
	}
	char* to_str() {
		char *ans = new char[len + 3]; int cnt = 0; clean();
		for (int i = len - 1; ~i; i--) ans[cnt++] = s[i] + '0';
		ans[cnt++] = 0; return ans;
	}
	friend ubint operator + (ubint a, ubint b);
	friend ubint operator - (ubint a, ubint b);
	friend ubint operator * (ubint a, ubint b);
	friend ubint operator * (ubint a, int b);
	friend ubint operator / (ubint a, ubint b);
	friend ubint operator / (ubint a, int b);
	friend ubint operator % (ubint a, ubint b);
	friend ubint operator % (ubint a, int b);
	ubint operator += (ubint a) { *this = *this + a; return *this; }
	ubint operator -= (ubint a) { *this = *this - a; return *this; }
	ubint operator *= (ubint a)	{ *this = *this * a; return *this; }
	ubint operator *= (int b);
	ubint operator /= (ubint a) { *this = *this / a; return *this; }
	bool operator < (ubint a)  	{ return cmp(a) < 0; }
	bool operator > (ubint a)  	{ return cmp(a) > 0; }
	bool operator <= (ubint a) 	{ return cmp(a) <= 0; }
	bool operator >= (ubint a) 	{ return cmp(a) >= 0; }
	bool operator == (ubint a) 	{ return cmp(a) == 0; }
	bool operator != (ubint a) 	{ return cmp(a) != 0; }
	ubint operator ++ (int)     { ubint tmp(*this); inc(); return tmp; }
	ubint operator ++ ()		{ inc(); return *this; }
	ubint operator -- (int)		{ ubint tmp(*this); dec(); return tmp; }
	ubint operator -- ()		{ dec(); return *this; }
	friend std::ostream& operator << (std::ostream&, const ubint&);
	friend std::istream& operator >> (std::istream&, ubint&);
};

ubint operator + (ubint a, ubint b) {
	ubint ans; ans.len = max(a.len, b.len) + 1;
	for (int i = 0; i < a.len || i < b.len; i++) {
		ans.s[i] += a.s[i] + b.s[i];
		if (ans.s[i] > 9) { ans.s[i] -= 10; ans.s[i + 1]++; }
	}
	ans.clean(); return ans;
}

ubint operator - (ubint a, ubint b) {
	ubint ans; ans.len = a.len + 1;
	for (int i = 0; i < a.len; i++) {
		ans.s[i] += a.s[i] - b.s[i];
		if (ans.s[i] < 0) { ans.s[i] += 10; ans.s[i + 1]--; }
	}
	ans.clean(); return ans;
}

ubint operator * (ubint a, ubint b) {
	if (b.len < 9) return a * b.to_int();
	ubint ans; ans.len = a.len + b.len + 1;
	for (int i = 0; i < a.len; i++)
		for (int j = 0; j < b.len; j++)
			ans.s[i + j] += a.s[i] * b.s[j];
	for (int i = 0; i < ans.len - 2; ans.s[i++] %= 10) 
		ans.s[i + 1] += ans.s[i] / 10;
	ans.clean(); return ans;
}

ubint operator * (ubint a, int b) {
	if (b > 99999999) return a * ubint(b);
	ubint ans; ans.len = a.len + 10;
	for (int i = 0; i < a.len; i++)
		ans.s[i] += a.s[i] * b;
	for (int i = 0; i < ans.len - 2; ans.s[i++] %= 10)
		ans.s[i + 1] += ans.s[i] / 10;
	ans.clean(); return ans;
}

ubint ubint::operator *= (int b) {
	if (b > 99999999) return (*this) * ubint(b);
	for (int i = 0; i < len; i++) s[i] *= b;
	len += 10;
	for (int i = 0; i < len - 2; s[i++] %= 10)
		s[i + 1] += s[i] / 10;
	clean(); return *this;
}

ubint operator / (ubint a, ubint b) {
	if (b.len < 10) return a / b.to_int();
	ubint ans, mod = 0; ans.len = a.len;
	for (int i = a.len - 1; ~i; i--) {
		for (int k = mod.len - 1; ~k; k--) mod.s[k + 1] = mod.s[k]; 
		mod.s[0] = a.s[i];
		for (; mod >= b; ans.s[i]++) mod -= b;
	}
	ans.clean(); return ans;
}

ubint operator / (ubint a, int b) {
	ubint ans; ans.len = a.len;
	long long mod = 0;
	for (int i = a.len - 1; ~i; i--) {
		mod *= 10; mod += a.s[i];
		ans.s[i] = mod / b; mod %= b;
	}
	ans.clean(); return ans;
}

ubint operator % (ubint a, ubint b) {
	if (b.len < 10) return a % b.to_int();
	ubint ans, mod = 0; ans.len = a.len;
	for (int i = a.len - 1; ~i; i--) {
		for (int k = mod.len - 1; ~k; k--) mod.s[k + 1] = mod.s[k]; 
		mod.s[0] = a.s[i];
		for (; mod >= b; ans.s[i]++) mod -= b;
	}
	mod.clean(); return mod;
}

ubint operator % (ubint a, int b) {
	ubint ans; ans.len = a.len;
	long long mod = 0;
	for (int i = a.len - 1; ~i; i--) {
		mod *= 10; mod += a.s[i];
		ans.s[i] = mod / b; mod %= b;
	}
	return int(mod);
}

std::ostream& operator << (std::ostream& out, const ubint& a) {
	for (int i = a.len - 1; ~i; i--) putchar(a.s[i] + '0');
	return out;
}

std::istream& operator >> (std::istream& cin, ubint& a) {
	char s[maxlen]; scanf("%s", s); a = ubint(s);
	return cin;
}

int main() {
	ubint a, b; cin >> a >> b;
	cout << a + b << endl;
    return 0;
}
