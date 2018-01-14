#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string text[101], a[101], b[101];
int line, n;

string match(string x) {
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return b[i];
	return "\0";
}

int main() {
	/*ifstream fin;
	fin.open("1.txt");
	fin >> line >> n;
	fin.get();
	*/
	cin >> line >> n;
	cin.get();
	for (int i = 0; i < line; i++)
		getline(cin, text[i]);
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		int j;
		for (j = 0; j < s.size(); j++)
			if (s[j] == ' ')
				break;
		a[i] = s.substr(0,j);
		b[i] = s.substr(j + 2, s.size() - j - 3);
	}

	for (int i = 0; i < line; i++) {
		string left = "{{ ";
		string right = " }}";
		int p = 0;
		for (;;)
			if (text[i].substr(p, 3) == left) {
				int q = p;
				for (;;)
					if (text[i].substr(q, 3) == right) {
						string ss = match(text[i].substr(p + 3, q - p - 3));
						string x = text[i].substr(0, p);
						string y = text[i].substr(q + 3, text[i].size() - 1);
						text[i] = x + ss + y;
						p += ss.size();
						break;
					} else {
						q++;
						if (q > text[i].size() - 3)
							break;
					}
			} else {
				p++;
				if (p > text[i].size() - 3)
					break;
			}
		cout << text[i] << endl;
	}

	return 0;
}
