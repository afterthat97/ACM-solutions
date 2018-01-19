#include <iostream>
#include <stdio.h>
using namespace std;

//0 1 2
//1 0 2
//1 2 0
//2 1 0
//2 0 1
//0 2 1
//0 1 2

int a[6][3] = {
	{0, 1, 2},
	{1, 0, 2},
	{1, 2, 0},
	{2, 1, 0},
	{2, 0, 1},
	{0, 2, 1}};

int main() {
	int n, k;
	cin >> n >> k;
	n %= 6;
	cout << a[n][k] << endl;
	return 0;
}
