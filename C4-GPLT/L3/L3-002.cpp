#include <stdio.h>
#include <cstring>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

int n, T;
stack<int> s;
multiset<int> s1, s2;

inline void adjust() {
	int size1 = s1.size(), size2 = s2.size();
	if (size1 == size2 || size1 == size2 + 1) return;
	else if (size1 > size2) {
		multiset<int>::iterator it = s1.end(); it--;
		s2.insert(*it); s1.erase(it);
	} else {
		multiset<int>::iterator it = s2.begin();
		s1.insert(*it); s2.erase(it);
	}
}

int main() {
	scanf("%d", &T);
	for (int idx = 0; idx < T; idx++) {
		char tmp[50]; scanf("%s", tmp);
		if (tmp[1] == 'u') {//push
			int v; scanf("%d", &v); s.push(v);
			if (s1.empty()) { s1.insert(v); continue; }
			multiset<int>::iterator it = s1.end(); it--;
			if (v <= *it) s1.insert(v);
			else s2.insert(v);
			adjust();
		} else if (tmp[1] == 'o') {//pop
			if (s.empty()) { puts("Invalid"); continue; }
			int v = s.top(); s.pop(); printf("%d\n", v);
			if (s1.find(v) != s1.end()) s1.erase(s1.find(v));
			else s2.erase(s2.find(v));
			adjust();
		} else {//peek
			if (s.empty()) { puts("Invalid"); continue; }
			multiset<int>::iterator it = s1.end(); it--;
			printf("%d\n", *it);
		}
	}

	return 0;
}
