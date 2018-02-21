#include "all.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
		return n ? dfs(1, n) : vector<TreeNode*>{};
    }
	vector<TreeNode*> dfs(int st, int ed) {
		vector<TreeNode*> ans;
		if (st > ed) ans.push_back(NULL);
		for (int i = st; i <= ed; i++) {
			vector<TreeNode*> left = dfs(st, i - 1);
			vector<TreeNode*> right = dfs(i + 1, ed);
			for (int l = 0; l < left.size(); l++)
				for (int r = 0; r < right.size(); r++) {
					TreeNode* root = new TreeNode(i);
					root->left = left[l];
					root->right = right[r];
					ans.push_back(root);
				}
		}
		return ans;
	}
};

int main() {
	int n;
	while (cin >> n) {
		vector<TreeNode*> ans = Solution().generateTrees(n);
		cout << ans.size() << endl;
	}

	return 0;
}
