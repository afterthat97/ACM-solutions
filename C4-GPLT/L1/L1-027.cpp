#include <iostream>
#include <stdio.h>
using namespace std;

char s[100];
bool app[10];
int idx[10], arr[10], cnt;

int main() {
	cin >> s;
	for (int i = 0; i < 11; i++)
		app[s[i] - '0'] = 1;
	for (int i = 9; ~i; i--)
		if (app[i]) {
			idx[i] = cnt;
			arr[cnt++] = i;
		}
	cout << "int[] arr = new int[]{" << arr[0];
	for (int i = 1; i < cnt; i++)
		cout << "," << arr[i];
	cout << "};\nint[] index = new int[]{" << idx[s[0] - '0'];
	for (int i = 1; i < 11; i++)
		cout << "," << idx[s[i] - '0'];
	cout << "};";
	return 0;
}
