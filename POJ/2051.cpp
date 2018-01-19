#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct item {
	int id, time, T;
};

struct cmp{
	bool operator ()(const item &a, const item &b) {
		if (a.time == b.time)
			return a.id > b.id;
		else
			return a.time > b.time;
	}
};

priority_queue<item, vector<item>, cmp > q;

int main() {
	while (1) {
		string temp;
		cin >> temp;
		if (temp[0] == '#') break;
		item t;
		cin >> t.id >> t.T;
		t.time = t.T;
		q.push(t);
	}
	int k; scanf("%d", &k);
	while (k--) {
		item cur = q.top();
		q.pop();
		cout << cur.id << endl;
		cur.time += cur.T;
		q.push(cur);
	}
	return 0;
}
