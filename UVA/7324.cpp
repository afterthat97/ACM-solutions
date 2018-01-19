#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <vector>
#include <ctime>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <memory>
#include <numeric>
#include <utility>

#define INF 999999999
#define uint unsigned int
#define uchar unsigned char
#define ll long long
#define ull unsigned long long
#define pause cin.get();cin.get();
#define read(i) scanf("%d", &i);
#define ln printf("\n");
using namespace std;

inline int get_num(string a, int &pos) {
	int num = a[pos++] - '0';
	while (a[pos] >= '0' && a[pos] <= '9')
		num = num * 10 + a[pos++] - '0';
	return num;
}

int main() {
	while (1) {
		string raw[10];
		for (int i = 0; i < 7; i++)
			if (!(cin >> raw[i])) return 0;
		int len = raw[0].size();
		int num = (len - 4) / 6 + 1;
		string trans = "";
		for (int i = 1; i <= num; i++) {// num th number 6*(i-1)
			int start = 6 * (i - 1);
			if (raw[0].substr(start, 5) == "xxxxx" && raw[6].substr(start, 5) == "xxxxx" && raw[3][start + 2] == '.') {
				trans = trans + "0";
				continue;
			}
			if (raw[0].substr(start, 5) == "....x") {
				trans = trans + "1";
				continue;
			}
			if (raw[1].substr(start, 5) == "....x" && raw[4].substr(start, 5) == "x....") {
				trans = trans + "2";
				continue;
			}
			if (raw[2].substr(start, 5) == "....x" && raw[3].substr(start, 5) == "xxxxx") {
				trans = trans + "3";
				continue;
			}
			if (raw[0].substr(start, 5) == "x...x") {
				trans = trans + "4";
				continue;
			}
			if (raw[1].substr(start, 5) == "x...." && raw[4].substr(start, 5) == "....x") {
				trans = trans + "5";
				continue;
			}
			if (raw[1].substr(start, 5) == "x...." && raw[4].substr(start, 5) == "x...x") {
				trans = trans + "6";
				continue;
			}
			if (raw[1].substr(start, 5) == "....x") {
				trans = trans + "7";
				continue;
			}
			if (raw[4].substr(start, 5) == "x...x") {
				trans = trans + "8";
				continue;
			}
			if (raw[1].substr(start, 5) == "x...x") {
				trans = trans + "9";
				continue;
			}
			trans = trans + "+";
		}

		int pos = 0;
		int a = get_num(trans, pos);
		pos++;
		int b = get_num(trans, pos);
		int t = a + b;

		string ans = "";
		while (t > 0) {
			ans = char(t % 10 + 48) + ans;
			t = t / 10;
		}
		for (int j = 0; j < ans.size(); j++) {//111111111111111111
			if (j > 0) cout << '.';
			if (ans[j] == '0')
				cout << "xxxxx";
			if (ans[j] == '1')
				cout << "....x";
			if (ans[j] == '2')
				cout << "xxxxx";
			if (ans[j] == '3')
				cout << "xxxxx";
			if (ans[j] == '4')
				cout << "x...x";
			if (ans[j] == '5')
				cout << "xxxxx";
			if (ans[j] == '6')
				cout << "xxxxx";
			if (ans[j] == '7')
				cout << "xxxxx";
			if (ans[j] == '8')
				cout << "xxxxx";
			if (ans[j] == '9')
				cout << "xxxxx";
		}
		cout << endl;

		for (int j = 0; j < ans.size(); j++) {//22222222222222222
			if (j > 0) cout << '.';
			if (ans[j] == '0')
				cout << "x...x";
			if (ans[j] == '1')
				cout << "....x";
			if (ans[j] == '2')
				cout << "....x";
			if (ans[j] == '3')
				cout << "....x";
			if (ans[j] == '4')
				cout << "x...x";
			if (ans[j] == '5')
				cout << "x....";
			if (ans[j] == '6')
				cout << "x....";
			if (ans[j] == '7')
				cout << "....x";
			if (ans[j] == '8')
				cout << "x...x";
			if (ans[j] == '9')
				cout << "x...x";
		}
		cout << endl;

		for (int j = 0; j < ans.size(); j++) {//33333333333
			if (j > 0) cout << '.';
			if (ans[j] == '0')
				cout << "x...x";
			if (ans[j] == '1')
				cout << "....x";
			if (ans[j] == '2')
				cout << "....x";
			if (ans[j] == '3')
				cout << "....x";
			if (ans[j] == '4')
				cout << "x...x";
			if (ans[j] == '5')
				cout << "x....";
			if (ans[j] == '6')
				cout << "x....";
			if (ans[j] == '7')
				cout << "....x";
			if (ans[j] == '8')
				cout << "x...x";
			if (ans[j] == '9')
				cout << "x...x";
		}
		cout << endl;

		for (int j = 0; j < ans.size(); j++) {//444444444
			if (j > 0) cout << '.';
			if (ans[j] == '0')
				cout << "x...x";
			if (ans[j] == '1')
				cout << "....x";
			if (ans[j] == '2')
				cout << "xxxxx";
			if (ans[j] == '3')
				cout << "xxxxx";
			if (ans[j] == '4')
				cout << "xxxxx";
			if (ans[j] == '5')
				cout << "xxxxx";
			if (ans[j] == '6')
				cout << "xxxxx";
			if (ans[j] == '7')
				cout << "....x";
			if (ans[j] == '8')
				cout << "xxxxx";
			if (ans[j] == '9')
				cout << "xxxxx";
		}
		cout << endl;

		for (int j = 0; j < ans.size(); j++) {//5555555
			if (j > 0) cout << '.';
			if (ans[j] == '0')
				cout << "x...x";
			if (ans[j] == '1')
				cout << "....x";
			if (ans[j] == '2')
				cout << "x....";
			if (ans[j] == '3')
				cout << "....x";
			if (ans[j] == '4')
				cout << "....x";
			if (ans[j] == '5')
				cout << "....x";
			if (ans[j] == '6')
				cout << "x...x";
			if (ans[j] == '7')
				cout << "....x";
			if (ans[j] == '8')
				cout << "x...x";
			if (ans[j] == '9')
				cout << "....x";
		}
		cout << endl;

		for (int j = 0; j < ans.size(); j++) {//666666
			if (j > 0) cout << '.';
			if (ans[j] == '0')
				cout << "x...x";
			if (ans[j] == '1')
				cout << "....x";
			if (ans[j] == '2')
				cout << "x....";
			if (ans[j] == '3')
				cout << "....x";
			if (ans[j] == '4')
				cout << "....x";
			if (ans[j] == '5')
				cout << "....x";
			if (ans[j] == '6')
				cout << "x...x";
			if (ans[j] == '7')
				cout << "....x";
			if (ans[j] == '8')
				cout << "x...x";
			if (ans[j] == '9')
				cout << "....x";
		}
		cout << endl;

		for (int j = 0; j < ans.size(); j++) {//7777777
			if (j > 0) cout << '.';
			if (ans[j] == '0')
				cout << "xxxxx";
			if (ans[j] == '1')
				cout << "....x";
			if (ans[j] == '2')
				cout << "xxxxx";
			if (ans[j] == '3')
				cout << "xxxxx";
			if (ans[j] == '4')
				cout << "....x";
			if (ans[j] == '5')
				cout << "xxxxx";
			if (ans[j] == '6')
				cout << "xxxxx";
			if (ans[j] == '7')
				cout << "....x";
			if (ans[j] == '8')
				cout << "xxxxx";
			if (ans[j] == '9')
				cout << "xxxxx";
		}
		cout << endl;
	}
	return 0;
}