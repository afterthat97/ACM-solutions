#include "all.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& mid) {
		int idx = 0;
		if (pre.size() == 0) return NULL;
        return solve(0, pre.size() - 1, idx, pre, mid);
    }
	TreeNode* solve(int a, int b, int& idx, vector<int>& pre, vector<int>& mid) {
		TreeNode* root = new TreeNode(pre[idx++]);
		int t = -1;
		for (int i = a; i <= b; i++)
			if (mid[i] == root->val) {
				t = i; break;
			}
		if (t > a) root->left = solve(a, t - 1, idx, pre, mid);
		if (t < b) root->right = solve(t + 1, b, idx, pre, mid);
		return root;
	}
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
