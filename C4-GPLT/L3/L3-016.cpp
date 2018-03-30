#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct node {
	node *l, *r, *sib;
	int val, depth;
	node(int v = 0):val(v), l(0), r(0) { l = r = sib = NULL; }
};

node* null_node = 0;//Don't use it

void ins(node* &root, int val) {
	if (root == 0) { root = new node(val); return; }
	if (val < root->val) ins(root->l, val);
	if (val > root->val) ins(root->r, val);
}

node* &find(node* &root, int val) {
	if (root == 0) { return null_node;}
	if (val < root->val) return find(root->l, val);
	if (val > root->val) return find(root->r, val);
	return root;
}

node* &getl(node* &root) { return (root->l == 0 ? root : getl(root->l)); }

void del(node* &root) {
	if (root->l == 0 && root->r == 0) {
		delete root; root = 0;
	} else if (root->l == 0) {
		node* tmp = root; root = root->r; delete tmp;
	} else if (root->r == 0) {
		node* tmp = root; root = root->l; delete tmp;
	} else {
		node* &tmp = getl(root->r); root->val = tmp->val; del(tmp);
	}
}

void bfs(node* root) {
	queue<node*> q;
	q.push(root);
	root->depth = 1;
	while (!q.empty()) {
		node* cnt = q.front(); q.pop();
		if (cnt->l && cnt->r) {
			cnt->l->sib = cnt->r;
			cnt->r->sib = cnt->l;
		}
		if (cnt->l) {
			cnt->l->depth = cnt->depth + 1;
			q.push(cnt->l);
		}
		if (cnt->r) {
			cnt->r->depth = cnt->depth + 1;
			q.push(cnt->r);
		}		
	}
}

node* root = NULL;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ins(root, x);
	}
	bfs(root);
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x;
		string str; cin >> str;
		if (str == "is") {
			cin >> str; cin >> str;
			if (str == "root") { // A is the root
				puts(root && root->val == x ? "Yes" : "No");
			} else if (str == "parent") { // A is the parent of B
				cin >> str >> y;
				node* &ans = find(root, x);
				if (ans == NULL) { puts("No"); continue; }
				puts(((ans->l && ans->l->val == y) ||
					(ans->r && ans->r->val == y)) ? "Yes" : "No");
			} else if (str == "left") { // A is the left child of B
				cin >> str >> str >> y;
				node* &ans = find(root, y);
				if (ans == NULL) { puts("No"); continue; }
				puts(ans->l && ans->l->val == x ? "Yes" : "No");
			} else if (str == "right") { // A is the right child of B
				cin >> str >> str >> y;
				node* &ans = find(root, y);
				if (ans == NULL) { puts("No"); continue; }
				puts(ans->r && ans->r->val == x ? "Yes" : "No");
			}
		} else { // and
			cin >> y >> str >> str;
			if (str == "siblings") { // A and B are siblings
				node* &ans = find(root, x);
				if (ans == NULL) { puts("No"); continue; }
				puts(ans->sib && ans->sib->val == y ? "Yes" : "No");
			} else { // A and B are on the same level
				cin >> str >> str >> str;
				node* &ans1 = find(root, x);
				if (ans1 == NULL) { puts("No"); continue; }
				node* &ans2 = find(root, y);
				if (ans2 == NULL) { puts("No"); continue; }
				puts(ans1->depth == ans2->depth ? "Yes" : "No");
			}
		}
	}
	return 0;
}
