#include <iostream>
#include <stdio.h>
using namespace std;

char str[100005];
char map[150];

int main() {
	int T; cin >> T;
	while (T--) {
		for (int i = 'A'; i <= 'z'; i++) map[i] = i;
		scanf("%s", str);
		int k; scanf("%d", &k); getchar();
		for (int i = 0; i < k; i++) {
			char from = getchar(); getchar();
			char to = getchar(); getchar();
			for (int i = 'A'; i <= 'Z'; i++)
				if (map[i] == from) map[i] = to;
		}
		for (int i = 0; str[i]; i++) putchar(map[str[i]]); putchar('\n');
	}
	return 0;
}
