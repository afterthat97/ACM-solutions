#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

int a[105], n;

int main() {
	cin >> n;
	int maxx = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] > maxx) maxx = a[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += maxx - a[i];
	cout << sum << endl;

	return 0;
}
