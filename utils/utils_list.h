#include <bits/stdc++.h>
using namespace std;

class ListNode {

  public:
    int _val;
    ListNode *next;
    ListNode(int val) : _val(val), next(nullptr) {}

    ListNode *buildByArr(vector<int> vals) {
        ListNode *_dummy = new ListNode(-1), *cur = _dummy;
        for (auto ele : vals) {
            ListNode *node = new ListNode(ele);
            cur->next = node;
            cur = cur->next;
        }
        return _dummy->next;
    }
    ListNode *buildByStr(string data) {
        ListNode *_dummy = new ListNode(-1), *cur = _dummy;
        stringstream ss(data);
        string tmp = "";
        while (getline(ss, tmp, ' ')) {
            ListNode *node = new ListNode(stoi(tmp));
            cur->next = node;
            cur = cur->next;
        }

        return _dummy->next;
    }
};
