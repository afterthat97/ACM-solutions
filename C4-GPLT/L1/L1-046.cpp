#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#define max(x, y) ((x) < (y) ? (y) : (x))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define maxlen 40005
#define ll long long
#define pi (acos(-1))
using namespace std;

class ubint {
public:
    int len, s[maxlen];
    void clean() { while (len > 1 && s[len - 1] == 0) len--; }
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
    ubint(const char* str) {
        memset(s, 0, sizeof s); len = (int)strlen(str);
        for (int i = 0; str[i]; i++) s[len - i - 1] = str[i] - '0';
    }
    ubint(int v = 0) {
        memset(s, 0, sizeof s);
        if (!v) { len = 1; s[0] = 0; return; }
        for (len = 0; v; v /= 10) s[len++] = v % 10;
    }
    ubint(const ubint& a) {
        len = a.len; memcpy(s, a.s, sizeof s); clean();
    }
    ubint& operator = (const ubint& a) {
        len = a.len; memcpy(s, a.s, sizeof s); clean(); return *this;
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
    friend ubint operator / (ubint a, int b);
    friend ubint operator % (ubint a, int b);
    bool operator < (ubint a)  	{ return cmp(a) < 0; }
    bool operator > (ubint a)  	{ return cmp(a) > 0; }
    bool operator <= (ubint a) 	{ return cmp(a) <= 0; }
    bool operator >= (ubint a) 	{ return cmp(a) >= 0; }
    bool operator == (ubint a) 	{ return cmp(a) == 0; }
    bool operator != (ubint a) 	{ return cmp(a) != 0; }
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

ubint operator * (ubint a, int b) {
    ubint ans; ans.len = a.len + 10;
    for (int i = 0; i < a.len; i++)
        ans.s[i] += a.s[i] * b;
    for (int i = 0; i < ans.len - 2; ans.s[i++] %= 10)
        ans.s[i + 1] += ans.s[i] / 10;
    ans.clean(); return ans;
}

ubint operator / (ubint a, int b) {
    ubint ans; ans.len = a.len; ll mod = 0;
    for (int i = a.len - 1; ~i; i--) {
        mod *= 10; mod += a.s[i];
        ans.s[i] = (int)(mod / (ll)b); mod %= b;
    }
    ans.clean(); return ans;
}

ubint operator % (ubint a, int b) {
    ubint ans; ans.len = a.len; ll mod = 0;
    for (int i = a.len - 1; ~i; i--) {
        mod *= 10; mod += a.s[i];
        ans.s[i] = (int)(mod / (ll)b); mod %= b;
    }
    return int(mod);
}

std::ostream& operator << (std::ostream& out, const ubint& a) {
    for (int i = a.len - 1; ~i; i--) out << (char)(a.s[i] + '0');
    return out;
}

std::istream& operator >> (std::istream& cin, ubint& a) {
    char s[maxlen]; cin >> s; a = ubint(s);
    return cin;
}

int main() {
	int n; cin >> n;
	ubint ans = 1; int tot = 1;
	while (ans % n != 0) {
		ans = ans * 10 + 1;
		tot++;
	}
	cout << ans / n << ' ' << tot << endl;
    return 0;
}
