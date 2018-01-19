#include <iostream>
using namespace std;

int main () {
	int n, ans = 1; cin >> n;
	for (int i = 0; i < n; i++) ans = ans * 2;
	cout << "2^" << n << " = "<< ans << endl;
	return 0;
}
