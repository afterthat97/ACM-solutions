#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;

string s;
int cannot[105][4];// R B Y G
int cnt[150];

int main() {
	cin >> s;
	bool move = 0;
	while (1) {
		move = 0;
		for (int i = 0; i < s.size(); i++) 
		if (s[i] != '!') {
			for (int j = 1; j < 30; j++) {
				if (i + 4 * j >= 0 && s[i + 4 * j] == '!') {
					cnt[s[i]]++;
					s[i + 4 * j] = s[i];
					move = 1;
				}
				if (i - 4 * j >= 0 && s[i - 4 * j] == '!') {
					cnt[s[i]]++;
					s[i - 4 * j] = s[i];
					move = 1;
				}	
			}
		}
		if (!move) break;
	}
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '!') {
			bool appear[150] = {};
			for (int j = -3; j <= 3; j++)
				if (i+j < s.size() && i+j >= 0)
					appear[s[i+j]] = 1;
			if (!appear['B']) cnt['B']++;
			if (!appear['R']) cnt['R']++;
			if (!appear['Y']) cnt['Y']++;
			if (!appear['G']) cnt['G']++;
		}
	cout << cnt['R'] << ' ' << cnt['B'] << ' ' << cnt['Y'] << ' ' << cnt['G'] << endl;
	return 0;
}
