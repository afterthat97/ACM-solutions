#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
struct node {
	string s;
	int state;
	node(int s, string ss):state(s), s(ss) {};
};

int n;
bool h[210];//h[]是个用来判重的bool数组
int main() {
	while (scanf("%d", &n) && n) {
		memset(h, 0, sizeof(h));
		queue<node> q;
		q.push(node(1, "1")); h[1] = 1;
		while (!q.empty()) {
			node now = q.front();
			q.pop();
			if (now.state == 0) {
				cout << now.s << endl;
				break;
			}
			int new1 = (now.state * 10 + 1) % n;//下一位是1
			int new2 = (now.state * 10) % n;//下一位是0
			if (!h[new1]) {
				q.push(node(new1, now.s + '1'));
				h[new1] = 1;
			}
			if (!h[new2]) {
				q.push(node(new2, now.s + '0'));
				h[new2] = 1;
			}
		}
	}
	return 0;
}