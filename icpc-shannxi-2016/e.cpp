#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

string s;
int num;

int main() {
	//freopen("e.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string tmp;
	while (getline(cin, tmp)) s = s + tmp + "\n";
	int len = s.size();
	bool dis = 0;
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == '/' && s[i + 1] == '*' && !dis) {
			for (int j = i + 2; j < len - 1; j++)
				if (s[j] == '*' && s[j + 1] == '/') {
					s.erase(i, j - i + 2); break; }
			i--;
		} else if (s[i] == '/' && s[i + 1] == '/') 
			dis = 1;
		else if (s[i] == '\n') dis = 0;

	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == '/' && s[i + 1] == '/') {
			for (int j = i + 2; j < s.size(); j++)
				if (s[j] == '\n') {
					s.erase(i, j - i); 
					break;
				}
		}
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '\n') {
			int j;
			for (j = i - 1; j >= 0; j--)
				if (s[j] != ' ' && s[j] != '\t')
					break;
			s.erase(j + 1, i - j - 1);
		}
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == '\n' && s[i + 1] == '\n') {
			s.erase(i, 1); i--;
		}
	while (s[s.size() - 1] == '\n') s.erase(s.size() - 1, 1);
	cout << s;
	return 0;
}
