#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
using namespace std;

struct node {
    int val;
    node *l, *r;
    node(int v = 0): val(v), l(0), r(0) {}
};

struct cmp {
    bool operator() (const node* a, const node* b) {
        return a->val > b->val;
    }
};

priority_queue<node*, vector<node*>, cmp> q;
int ans;

node* huffman() {
    node* cur = NULL;
    while (q.size() > 1) {
        cur = new node;
        cur->l = q.top(); q.pop();
        cur->r = q.top(); q.pop();
        cur->val = cur->l->val + cur->r->val;
        ans += cur->val;
        q.push(cur);
    }
    return q.top();
}

int main() {
    string s;
    while ((cin >> s) && (s != "END")) {
        ans = 0;
        int len = s.size(), cnt[200] = {};
        while (!q.empty()) q.pop();
        for (int i = 0; i < len; i++) cnt[s[i]]++;
        for (int i = 0; i < 200; i++)
            if (cnt[i]) q.push(new node(cnt[i]));
        if (q.size() == 1)
            ans = q.top()->val;
        else
            huffman();
        printf("%d %d %.1f\n", len * 8, ans, (len * 8 * 1.0) / ans);
    }
    return 0;
}