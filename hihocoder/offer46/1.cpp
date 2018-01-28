#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 1000005
using namespace std;

char str[maxn];
int A, E, I, O, U;

int main() {
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		int num = 0;
		if (str[i] <= 'i') {
			if (str[i] >= 'a') num = max(num, A);
			if (str[i] >= 'e') num = max(num, E);
			if (str[i] >= 'i') num = max(num, I);
			if (str[i] == 'a') A = max(A, num + 1);
			if (str[i] == 'e') E = max(E, num + 1);
			if (str[i] == 'i') I = max(I, num + 1);
		} else {
			if (str[i] >= 'o') num = max(num, O);
			if (str[i] >= 'u') num = max(num, U);
			if (str[i] == 'o') O = max(O, num + 1);
			if (str[i] == 'u') U = max(U, num + 1);
		}
	}
	cout << max(max(A, E), I) + max(O, U) << endl;
	return 0;
}
