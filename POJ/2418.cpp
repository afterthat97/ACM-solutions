#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<string, int> a;
int sum;
string name;

int main() {
	while (getline(cin, name)) {
		if (name == "")break;
		a[name]++;
		sum++;
	}
	for (map<string, int>::iterator i = a.begin(); i != a.end(); i++) {
		printf("%s %.4f\n", (i->first).c_str(), ((i->second * 100.0) / sum));
	}
	return 0;
}
