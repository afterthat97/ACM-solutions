#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	double avg = 0, t;
	for (int i = 0; i < 12; i++) {
		cin >> t;
		avg += t;
	}
	printf("$%.2f\n", avg / 12);
}
