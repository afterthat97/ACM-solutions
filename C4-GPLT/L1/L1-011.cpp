#include <iostream>
#include <string>
using namespace std;

bool app[150];

int main() {
	string s, p;
	getline(cin, s);
	getline(cin, p);
	for (int i = 0; i < p.size(); i++) app[p[i]] = 1;
	for (int i = 0; i < s.size(); i++)
		if (app[s[i]]) {
			s.erase(i, 1);
			i--;
		}
	cout << s << endl;
	return 0;
}
