#include <cstring>
#include <iostream>
using namespace std;

char s[100];
int k;

int main() {
	cin >> s >> k;
	int len = strlen(s);

	int ans = 0;
	for (int i = len - 1; i > -1; i--) {
		if (s[i] == '0') k--;
		else ans++;
		if (k == 0)break;
	}

	if (k != 0) {
		ans = len - 1;
	}
	cout << ans << endl;
	return 0;
}
