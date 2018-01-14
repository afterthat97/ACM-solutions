#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string name[10005], arr[10005];
int num[10005], cnt;
map<string, bool> list;
double sum;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		list[s] = 1;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> name[i] >> num[i];
		sum += num[i];
	}
	bool have = 0;
	double avg = sum / m;
	for (int i = 0; i < m; i++) 
		if (!list[name[i]] && num[i] > avg) 
			arr[cnt++] = name[i];
	sort(arr, arr + cnt);
	for (int i = 0; i < cnt; i++) 
		cout << arr[i] << endl;
	if (!cnt) printf("Bing Mei You");
	return 0;
}
