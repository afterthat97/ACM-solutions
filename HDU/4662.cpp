#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char str[1000005];

int main() {
	int T; cin >> T;
	while (scanf("%s", str) == 1) {
		int len = strlen(str), cm = 0, cu = 0, ci = 0;
		for (int i = 0; i < len; i++)
			if (str[i] == 'M')
				cm++;
			else if (str[i] == 'U')
				cu++;
			else
				ci++;
		ci += cu * 3;
		bool succ = 0;
		if (cm == 1 && str[0] == 'M')
			if (ci == 1 || (ci % 2 == 0 && ci % 3 != 0))
				succ = 1;
		puts(succ ? "Yes" : "No");
			
	}

	return 0;
}
