#include "all.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> newq, q;
		if (root != NULL) newq.push(root);
		while (!newq.empty()) {
			q = newq; newq = queue<TreeNode*>();
			vector<int> cntLevel;
			while (!q.empty()) {
				TreeNode* cnt = q.front(); q.pop();
				if (cnt == NULL) continue;
				cntLevel.push_back(cnt->val);
				if (cnt->left) newq.push(cnt->left);
				if (cnt->right) newq.push(cnt->right);
			}
			ans.push_back(cntLevel);
		}
		reverse(ans.begin(), ans.end());
		return ans;
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
        TreeNode* p = stringToTreeNode(line);
        vector<vector<int>> ret = Solution().levelOrderBottom(p);
		cout << '[' << endl;
		for (int i = 0; i < ret.size(); i++) {
			string out = integerVectorToString(ret[i]);
			cout << "  " << out << ',' << endl;
		}
		cout << ']' << endl;
    }
    return 0;
}
