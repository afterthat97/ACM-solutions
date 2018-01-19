#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;

int tree[MAXN], n;//1..n

inline int sum(int x) {
	int ans = 0;
	for (; x > 0; x -= (x & -x))
		ans += tree[x];
	return ans;
}

int main() {

	return 0;
}
