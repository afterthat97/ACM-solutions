#include "all.h"

typedef pair<int, ListNode*> node;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<node, vector<node>, greater<node> > q;
        for (int i = 0; i < lists.size(); i++)
			if (lists[i]) q.push(node(lists[i]->val, lists[i]));
		ListNode *head = new ListNode(-1), *p = head;
		while (!q.empty()) {
			node cnt = q.top(); q.pop();
			if (cnt.second->next)
				q.push(node(cnt.second->next->val, cnt.second->next));
			p->next = new ListNode(cnt.first);
			p = p->next;
		}
		return head->next;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
	int n; cin >> n;
	vector<ListNode*> lists(n);
	for (int i = 0; i < n; i++) {
		cin >> line;
		ListNode* l = stringToListNode(line);
		lists.push_back(l);
	}
    ListNode* ret = Solution().mergeKLists(lists);
	string out = listNodeToString(ret);
	cout << out << endl;
    return 0;
}
