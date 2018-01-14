#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <cstring>
#define MAXN 100005
#define ll long long
using namespace std;

int factor[76][76];

void getf(int x) {
	int t = x;
	for (int i = 2; i * i <= x; i++)
		while (x % i == 0) {
			factor[t][i]++;
			x /= i;
		}
	if (x != 1) factor[t][x]++;	
}

int main() {
	for (int x = 2; x <= 75; x++) getf(x);
	int n; cin >> n; ll sum = 0;
	if (n & 1) {
		for (int i = 1; n - 3 * i >= 0; i += 2) {
			int j = (n - 3 * i) / 2; // ans = (i + j)! / (i!j!)
			int ans[76] = {};
			for (int k = 2; k <= i + j; k++)
				for (int l = 1; l <= 75; l++)
					ans[l] += factor[k][l];
			for (int k = 2; k <= i; k++)
				for (int l = 1; l <= 75; l++)
					ans[l] -= factor[k][l];
			for (int k = 2; k <= j; k++)
				for (int l = 1; l <= 75; l++)
					ans[l] -= factor[k][l];
			ll all = 1;
			for (int l = 1; l <= 75; l++)
				for (int k = 0; k < ans[l]; k++)
					all *= l;
			sum += all;
		}
	} else {
		for (int i = 0; n - 3 * i >= 0; i += 2) {
			int j = (n - 3 * i) / 2; // ans = (i + j)! / (i!j!)
			int ans[76] = {};
			for (int k = 2; k <= i + j; k++)
				for (int l = 1; l <= 75; l++)
					ans[l] += factor[k][l];
			for (int k = 2; k <= i; k++)
				for (int l = 1; l <= 75; l++)
					ans[l] -= factor[k][l];
			for (int k = 2; k <= j; k++)
				for (int l = 1; l <= 75; l++)
					ans[l] -= factor[k][l];
			ll all = 1;
			for (int l = 1; l <= 75; l++)
				for (int k = 0; k < ans[l]; k++)
					all *= l;
			sum += all;
		}
	}
	cout << sum << endl;
	return 0;
}
