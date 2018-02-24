#include "all.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeLinkNode *cnt = q.front(); q.pop();
                if (i < n - 1) cnt->next = q.front();
                if (cnt->left) q.push(cnt->left);
                if (cnt->right) q.push(cnt->right);
            }
        }
    }
};
