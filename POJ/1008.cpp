#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int num, n;
string hab[19] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
string tzo[21] = { "ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
map<string, int> f1;

int main() {
	cin >> num;
	cout << num << endl;
	for (int i = 0; i < 19; i++)
		f1[hab[i]] = i + 1;

	for (int i = 0; i < num; i++) {
		int day, month, year;
		string temp;
		cin >> day >> temp >> temp >> year;
		month = f1[temp];
		int sum = year * 365 + (month - 1) * 20 + day + 1;
		int ty = sum / 260;
		if (sum % 260) {
			if ((sum - ty * 260) % 13)
				cout << (sum - ty * 260) % 13 << ' ';
			else
				cout << 13 << ' ';
			cout << tzo[(sum - ty * 260) % 20] << ' ' << ty << endl;
		} else {
			ty--;
			if ((sum - ty * 260) % 13)
				cout << (sum - ty * 260) % 13 << ' ';
			else
				cout << 13 << ' ';
			cout << tzo[(sum - ty * 260) % 20] << ' ' << ty << endl;
		}
	}
	return 0;
}