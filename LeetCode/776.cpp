#include "all.h"

class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
		vector<TreeNode*> ans(2, NULL);
		if (root == NULL) return ans;
		if (V < root->val) {
			ans = splitBST(root->left, V);
			root->left = ans[1];
			ans[1] = root;
		} else {
			ans = splitBST(root->right, V);
			root->right = ans[0];
			ans[0] = root;
		}
		return ans;
    }
};

int main() {
	return 0;
}
