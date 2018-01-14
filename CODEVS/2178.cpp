#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std;

stack<int> num;
stack<char> opt;

inline int pow(const int& a, const int& b) {
	int ans = 1;
	for (int i = 0; i < b; i++)
		ans *= a;
	return ans;
}

inline char* init(char *a) {
	int cnt = 0, len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (a[i] == '(') cnt++;
		if (a[i] == ')') cnt--;
	}
	if (cnt >= 0) {
		for (int i = 0; i <= cnt; i++) a[len + i] = ')';
		a[len + cnt + 1] = 0;
	} else {
		a[len] = ')';
		a[len + 1] = 0;
		char *temp = new char[1000];
		for (int i = 0; i < -cnt; i++) temp[i] = '(';
		temp[-cnt] = 0;
		strcat(temp, a);
		a = temp;
	}
	return a;
}

inline bool get_num(char *a, int& num, int &pos) {
	if (a[pos] < '0' || a[pos] > '9') return false;
	num = a[pos++] - '0';
	while (a[pos] >= '0' && a[pos] <= '9')
		num = num * 10 + a[pos++] - '0';
	return true;
}

inline void rm_blank(char* a) {
	int j = 0, len = strlen(a);
	for (int i = 0; i < len; i++)
		if (a[i] != ' ') {
			if (i != j) a[j] = a[i];
			j++;
		}
	a[j] = 0;
}

inline int cal(char opt, int a, int b) {
	switch (opt) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
	return pow(a, b);
}

inline void work(int &x) {
	x = cal(opt.top(), num.empty() ? 0 : num.top(), x);
	if (!num.empty()) num.pop();
	opt.pop();
}

int main() {
	char *s = new char[1000];
	int digit = 0;
	while (scanf("%s", s) != EOF) {
		s = init(s);
		int len = strlen(s);
		while (!opt.empty()) opt.pop();
		while (!num.empty()) num.pop();
		opt.push('(');
		for (int i = 0; i < len; i++)
			if (get_num(s, digit, i)) {
				while (opt.top() == '^') work(digit);
				while ((opt.top() == '*' || opt.top() == '/') && s[i] != '^') work(digit);
				while (opt.top() == '-' && s[i] != '^') {
					digit = -digit;
					opt.pop();
					opt.push('+');
				}
				i--;
				num.push(digit);
			} else if (s[i] == ')') {
				digit = num.top(); num.pop();
				while (opt.top() != '(') work(digit);
				opt.pop();
				if (!opt.empty()) {
					while (opt.top() == '^') work(digit);
					while ((opt.top() == '*' || opt.top() == '/') && s[i + 1] != '^') work(digit);
					while (opt.top() == '-' && s[i + 1] != '^') {
						digit = -digit;
						opt.pop();
						opt.push('+');
					}
				}
				num.push(digit);
			} else
				opt.push(s[i]);
			printf("%d\n", num.top());
	}
	return 0;
}
