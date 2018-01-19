#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string s;
int a, b;//aX=b

int main() {
	cin >> s;
	char X;
	if (s[0] != '-') s = '+' + s;
	for (int i = 0; i <= s.size() - 1; i++)
		if ((s[i] > 96) && (s[i] < 123))
			X = s[i];

	for (int i = 0; i <= s.size() - 1; i++)
		if (s[i] == '=') {
			if (s[i + 1] != '-')s[i] = '-';
			else {
				s[i + 1] = '+';
				s.erase(i, 1);
			}
			for (int j = i + 1; j <= s.size() - 1; j++)
				if (s[j] == '+')
					s[j] = '-';
				else if (s[j] == '-')
					s[j] = '+';
			break;
		}

	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] == '+')
			for (int j = i + 1; j <= s.size(); j++)
				if ((s[j] > 57) || (s[j] < 48)) {
					if ((s[j] == '-') || (s[j] == '+') || (s[j] == 0))
						b += atoi(s.substr(i + 1, j - i - 1).c_str());
					else
						a += atoi(s.substr(i + 1, j - i - 1).c_str());
					break;
				}
		if (s[i] == '-')
			for (int j = i + 1; j <= s.size(); j++)
				if ((s[j] > 57) || (s[j] < 48)) {
					if ((s[j] == '-') || (s[j] == '+') || s[j] == 0)
						b -= atoi(s.substr(i + 1, j - i - 1).c_str());
					else
						a -= atoi(s.substr(i + 1, j - i - 1).c_str());
					break;
				}
	}

	printf("%c=%.3f", X, -b / (a*1.0));
	system("pause");
	return 0;
}