#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int cho[5], val[30], snum, ans[5], ansnum, ansdiff, ansmax, sum;
bool tie;

inline void copytoans(int num) {
	tie = 0;
	ansdiff = 1; ansmax = 0; ansnum = num;
	for (int i = 0; i < num; i++) {
		ans[i] = cho[i];
		if (i && ans[i] != ans[i - 1]) ansdiff++;
		if (val[cho[i]] > ansmax) ansmax = val[cho[i]];
	}
	ansnum = num;
}

inline void check(int num) {
	int diff = 1;
	for (int i = 1; i < num; i++)
		if (cho[i] != cho[i - 1]) diff++;
	if (diff > ansdiff) copytoans(num);
	else if (diff == ansdiff) {
		if (num < ansnum) copytoans(num);
		else if (num == ansnum) {
			int maxx = 0;
			for (int i = 0; i < num; i++)
				if (val[cho[i]] > maxx) maxx = val[cho[i]];
			if (maxx > ansmax) copytoans(num);
			else if (maxx == ansmax) tie = 1;
		}
	}
}

void dfs(int sum, int num, int pre) {
	if (sum == 0) { check(num); return; }
	if (num == 4) return;
	for (int i = pre; i < snum; i++) 
		if (sum - val[i] >= 0) {
			cho[num++] = i;
			dfs(sum - val[i], num, i);
			--num;
		}
}

int main() {
	while (scanf("%d", &val[0]) == 1 && val[0]) {
		for (snum = 1; scanf("%d", &val[snum]) == 1 && val[snum]; snum++);
		sort(val, val + snum);
		while (scanf("%d", &sum) == 1 && sum) {
			ansdiff = 0; tie = 0;
			dfs(sum, 0, 0);
			if (ansdiff == 0) printf("%d ---- none\n", sum);
			else if (tie) printf("%d (%d): tie\n", sum, ansdiff);
			else {
				printf("%d (%d):", sum, ansdiff);
				for (int i = 0; i < ansnum; i++)
					printf(" %d", val[ans[i]]);
				putchar('\n');
			}
		}
	}
	return 0;
}
