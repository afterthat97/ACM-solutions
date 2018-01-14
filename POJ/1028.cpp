#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

stack<string> back, forw;
string opt, site, cnt;

int main() {
	cnt = ("http://www.acm.org/");
	while (cin >> opt) {
		if (opt == "QUIT") break;
		else if (opt == "VISIT") {
			back.push(cnt);
			cin >> site;
			cnt = site;
			cout << cnt << endl;
			while (!forw.empty()) forw.pop();
		} else if (opt == "BACK") {
			if (back.empty()) {
				cout << "Ignored" << endl;
			} else {
				forw.push(cnt);
				cnt = back.top(); back.pop();
				cout << cnt << endl;
			}
		} else { // Forward
			if (forw.empty()) {
				cout << "Ignored" << endl;
			} else {
				back.push(cnt);
				cnt = forw.top(); forw.pop();
				cout << cnt << endl;
			}
		}
	}
	return 0;
}
