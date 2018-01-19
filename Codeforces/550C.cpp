#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char str[105];

bool div8(int i, int j, int k) {
	i = str[i] - '0';
	j = str[j] - '0';
	k = str[k] - '0';
	if ((i * 100 + j * 10 + k) % 8 == 0) return 1;
	else return 0;
}

int main() {
	scanf("%s", str + 3);
	str[0] = str[1] = str[2] = '0';
	int len = strlen(str);

	int l = 0, r = len, maxx = -1;
	while (l < r) {
		int mid = (l + r) / 2;
		bool succ = 0;
		for (int i = mid; i < len; i++)
			for (int j = i + 1; j < len; j++)
				for (int k = j + 1; k < len; k++)
					if (div8(i, j, k) && (i > 2 || j > 2 || k > 2)) {
						succ = 1; break;
					}
		if (succ) {
			maxx = mid;
			l = mid + 1;
		} else r = mid;
	}
	
	if (maxx != -1)
		for (int i = maxx; i < len; i++)
			for (int j = i + 1; j < len; j++)
				for (int k = j + 1; k < len; k++)
					if (div8(i, j, k)) {
						puts("YES");
						bool flag = 0;
						for (int m = 0; m < i; m++)
							if (str[m] != '0' || flag) {
								flag = 1;
								putchar(str[m]);
							}
						for (int m = i; m < len; m++)
							if (m == i || m == j || m == k)
								if (str[m] != '0' || flag) {
									flag = 1;
									putchar(str[m]);
								}
						if (flag == 0) putchar(48);
						return 0;
					}
	puts("NO");
	return 0;
}
