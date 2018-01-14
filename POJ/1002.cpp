#include <string>
#include <cstring>
#include <cstdio>

int map[256];
const int pow10[7] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
int num[10000000];
char str[10000];

int main() {
	map['A'] = map['B'] = map['C'] = 2;
	map['D'] = map['E'] = map['F'] = 3;
	map['G'] = map['H'] = map['I'] = 4;
	map['J'] = map['K'] = map['L'] = 5;
	map['M'] = map['N'] = map['O'] = 6;
	map['P'] = map['R'] = map['S'] = 7;
	map['T'] = map['U'] = map['V'] = 8;
	map['W'] = map['X'] = map['Y'] = 9;
	int n; scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		gets(str);
		int len = strlen(str), cnt = 0, res = 0;
		for (int i = len - 1; ~i; i--)
			if (str[i] >= '0' && str[i] <= '9')
				res += (str[i] - '0') * pow10[cnt++];
			else if (str[i] != '-')
				res += map[str[i]] * pow10[cnt++];
		num[res]++;
	}
	bool dup = 0;
	for (int i = 0; i < 10000000; i++)
		if (num[i] > 1) {
			printf("%03d-%04d %d\n", i / 10000, i % 10000, num[i]);
			dup = 1;
		}
	if (!dup) puts("No duplicates.");
	return 0;
}
