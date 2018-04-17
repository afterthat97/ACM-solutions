#include "all.h"

#define LETTER 26

struct node {
	int num, next[LETTER];
	node() {
		num = 0;
		memset(next, 0, sizeof next);
	}
};

void ins_trie(vector<node>& trie, string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
		if (trie[cnt].next[s[i] - 'a'] == 0) {
			trie[cnt].next[s[i] - 'a'] = trie.size();
			trie.push_back(node());
		}
		cnt = trie[cnt].next[s[i] - 'a'];
    }
	++trie[cnt].num;
}

void dfs(vector<vector<char>>& board, int x, int y, vector<node>& trie, int idx, string cnt, vector<string>& ans) {
	char ch = board[x][y];
	if (ch == '.' || trie[idx].next[board[x][y] - 'a'] == 0) return;

	cnt = cnt + board[x][y];
	int next_idx = trie[idx].next[board[x][y] - 'a'];
	if (trie[next_idx].num > 0) {
		trie[next_idx].num = 0;
		ans.push_back(cnt);
	}
	board[x][y] = '.';
	if (x > 0) dfs(board, x - 1, y, trie, next_idx, cnt, ans);
	if (y > 0) dfs(board, x, y - 1, trie, next_idx, cnt, ans);
	if (x < board.size() - 1) dfs(board, x + 1, y, trie, next_idx, cnt, ans);
	if (y < board[0].size() - 1) dfs(board, x, y + 1, trie, next_idx, cnt, ans);
	board[x][y] = ch;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
		vector<node> trie(1, node());
		for (int i = 0; i < words.size(); i++)
			ins_trie(trie, words[i]);
		int n = board.size();
		if (n == 0) return ans;
		int m = board[0].size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				dfs(board, i, j, trie, 0, "", ans);
		sort(ans.begin(), ans.end());
		return ans;
    }
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int k; cin >> k;
	vector<string> words(k);
	for (int i = 0; i < k; i++)
		cin >> words[i];
	vector<string> ans = Solution().findWords(board, words);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
