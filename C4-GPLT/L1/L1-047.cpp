#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n, a, b; cin >> n;
	char name[10];
	while (scanf("%s %d %d", name, &a, &b) == 3)
		if (a < 15 || a > 20 || b < 50 || b > 70)
			cout << name << endl;
	return 0;
}
