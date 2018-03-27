#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	int n, cnt = 1; cin >> n; ++n;
	string str;
	while (cin >> str && str != "End") {
		if (cnt % n == 0)
			cout << str << endl;
		else if (str == "ChuiZi")
			cout << "Bu" << endl;
		else if (str == "JianDao")
			cout << "ChuiZi" << endl;
		else
			cout << "JianDao" << endl;
		cnt++;
	}
	return 0;
}
