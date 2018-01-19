#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = 0, jc = 1;
	for (int i = 1; i <= n; i++) {
		jc *= i;
		ans += jc;
	}
	cout << ans << endl;
	return 0;
}
