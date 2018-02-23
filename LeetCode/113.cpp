#include "all.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		vector<int> path;
		solve(path, ans, root, sum);
		return ans;
    }
	void solve(vector<int>& path, vector<vector<int>>& ans, TreeNode* root, int sum) {
		if (root == NULL) return;
		path.push_back(root->val);
		if (root->val == sum && !root->left && !root->right)
			ans.push_back(path);
		else {
			solve(path, ans, root->left, sum - root->val);
			solve(path, ans, root->right, sum - root->val);
		}
		path.pop_back();
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

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);
        
        vector<vector<int>> ret = Solution().pathSum(root, sum);
		
		cout << '[' << endl;
		for (int i = 0; i < ret.size(); i++) {
			string out = integerVectorToString(ret[i]);
			cout << "  " << out << ',' << endl;
		}
		cout << ']' << endl;
    }
    return 0;
}
