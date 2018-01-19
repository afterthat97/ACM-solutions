#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a == 1) {
		cout << 1;
		return 0;
	}
	int aa = (b / a)*a;
	int x = b / a;
	while (1) {
		aa %= b;
		if (aa == 1) {
			cout << x;
			return 0;
		}
		aa += a;
		x++;
	}
	return 0;
}