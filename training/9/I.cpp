#include <iostream>
#include <stdio.h>
using namespace std;

char s[5050];
int size, trie[26 * 5050][26];

void insert(char* s) {
    int p = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (!trie[p][c]) trie[p][c] = ++size;
        p = trie[p][c];
    }
}

int main() {
	while (scanf("%s", s) == 1) {
		memset(trie, 0, sizeof trie);
		size = 0;
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			char* cnt = s + i;
			insert(cnt);
		}
		printf("%d\n", size);
	}
	return 0;
}