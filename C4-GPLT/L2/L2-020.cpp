#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <cmath>
#define maxn 100005
using namespace std;

double z[maxn], r;
vector<int> stu[maxn];
double su[maxn];
bool got[maxn], de[maxn];
int n, all = 1;

int main() {
	memset(su, 0, sizeof su);
	scanf("%d %lf %lf", &n, &z[0], &r);
	r = (100 - r) / 100;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		if (k == 0) {
			double t; cin >> t;
			su[i] = t; de[i] = 1;
		} else
			for (int j = 0; j < k; j++) {
				int t; cin >> t;
				stu[i].push_back(t);
			}
	}
	got[0] = 1;
	while (all < n) {
		for (int i = 0; i < n; i++)
			if (got[i] && !de[i]) 
				for (int j = 0; j < stu[i].size(); j++)
					if (!got[stu[i][j]]) {
						got[stu[i][j]] = 1;
						z[stu[i][j]] = z[i] * r;
						all++;
					}		
	}
	double ans = 0;
	for (int i = 0; i < n; i++)
		ans += (de[i] ? su[i] * z[i] : 0);
	cout << (long long)floor(ans);
	return 0;
}
