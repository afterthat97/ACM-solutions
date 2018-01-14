#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
using namespace std;

struct node {
	string content;
	string user;
	bool cannot[105];
	node() {
		content = "";
		user = "";
		memset(cannot, 0 ,sizeof cannot);
	}
}info[105];

string name[105];

int T, n, m;

void print() {
	for (int i = 1; i <= m; i++) {
		cout << info[i].user << ":" << info[i].content << endl;
	}
}

void dfs(int x) {
	if (x == m + 1) print();
	if (info[x].user != "") 
		dfs(x + 1);
	else {
		for (int i = 0; i < n; i++)
			if (!info[x].cannot[i]) {
				info[x].user = name[i];
				info[x + 1].cannot[i] = 1;
				dfs(x + 1);
				info[x].user = "";
				info[x + 1].cannot[i] = 0;
			}
	}
}

int main() {
	cin >> T;
	for (int idx = 0; idx < T; idx++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> name[i];
		cin >> m;
		for (int i = 1; i <= m; i++) {
			memset(info[i].cannot, 0, sizeof(info[i].cannot));
			info[i].user = "";
			info[i].content = "";
			string tmp;
			do {
				getline(cin, tmp);
			} while (tmp == "");
			
			for (int j = 0; j < tmp.size(); j++)
				if (tmp[j] == ':') {
					info[i].content = tmp.substr(j + 1, tmp.size()-j-1);
					if (tmp[0] != '?') {
						info[i].user = tmp.substr(0, j);
						for (int k = 0; k < n; k++)
							if (name[k] == info[i].user)
								info[i + 1].cannot[k] = info[i - 1].cannot[k] = 1;
					}
					break;
				}
			cout << "1";
			if (tmp[0] == '?')
				for (int j = 0; j < n; j++) {
					size_t found = tmp.find(name[j]);
					if (found != string::npos)
						info[i].cannot[j] = 1;
				}
		}
		dfs(1);
		cout << "Impossible\n";
	}

	return 0;
}
