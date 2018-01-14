#include <iostream>
#include <string>
using namespace std;

string a[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
	string s; cin >> s;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == '-') cout << "fu ";
		else cout << a[s[i] - 48] << ' ';
	}
	cout << a[s[s.size() - 1] - 48];
	return 0;
}
