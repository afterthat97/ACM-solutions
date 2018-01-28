#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <cmath>
#include <stdlib.h>
#include <climits>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
	int start, end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
