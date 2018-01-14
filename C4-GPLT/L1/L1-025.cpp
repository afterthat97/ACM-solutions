#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

char *a, *b;

int main() {
	a = new char[1000];
	b = new char[1000];
	bool succ1 = 1, succ2 = 1;
	string t;
    getline(cin, t);
    for(int i = 0; i < t.length(); i++) {
        if(t[i] == ' ') {
            strcpy(a, t.substr(0, i).c_str());
            strcpy(b, t.substr(i + 1, t.size()- i - 1).c_str());
            break;
        }
    }
	int lena = strlen(a), lenb = strlen(b);
	for (int i = 0; i < lena; i++)
		if (a[i] < '0' || a[i] > '9')
			succ1 = 0;
	for (int i = 0; i < lenb; i++)
		if (b[i] < '0' || b[i] > '9')
			succ2 = 0;
	if (lena > 4) succ1 = 0;
	if (lenb > 4) succ2 = 0;
	int aa, bb;
	if (succ1) {
		sscanf(a, "%d", &aa);
		if (aa < 1 || aa > 1000) succ1 = 0;
	}
	if (succ2) {
		sscanf(b, "%d", &bb);
		if (bb < 1 || bb > 1000) succ2 = 0;
	}
	if (succ1) cout << aa; else cout << "?";
	cout << " + ";
	if (succ2) cout << bb; else cout << "?";
	cout << " = ";
	if (succ1 && succ2) cout << aa + bb; else cout << "?";
	return 0;
}
