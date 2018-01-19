#include <iostream>
#include <stdio.h>
using namespace std;

char s[15][15] = {};

int main() {
	for (int i = 5; i <= 8; i++)
		for (int j = 5; j <= 8; j++)
			cin >> s[i][j];

	bool win = 0;
	for (int i = 5; i <= 8; i++)
		for (int j = 5; j <= 8; j++) 
			if (s[i][j] == '.' || s[i][j] == 'x') {
				if (s[i - 1][j] == 'x' && s[i - 2][j] == 'x') win = 1;
				if (s[i - 1][j] == 'x' && s[i + 1][j] == 'x') win = 1;
				if (s[i + 2][j] == 'x' && s[i + 1][j] == 'x') win = 1;
				if (s[i][j - 2] == 'x' && s[i][j - 1] == 'x') win = 1;
				if (s[i][j - 1] == 'x' && s[i][j + 1] == 'x') win = 1;
				if (s[i][j + 1] == 'x' && s[i][j + 2] == 'x') win = 1;
				if (s[i - 1][j -1] == 'x' && s[i - 2][j - 2] == 'x')win=1;
				if (s[i +1][j +1] == 'x' && s[i + 2][j + 2] == 'x')win=1;
				if (s[i - 1][j -1] == 'x' && s[i + 1][j +1] == 'x')win=1;
				if (s[i - 1][j +1] == 'x' && s[i - 2][j + 2] == 'x')win=1;
				if (s[i +1][j -1] == 'x' && s[i + 2][j - 2] == 'x')win=1;
				if (s[i - 1][j +1] == 'x' && s[i + 1][j -1] == 'x')win=1;
			}
	if (win) 
		cout << "YES\n";
	else 
		cout << "NO\n";


	return 0;
}
