#include "../utils_list.h"

class Solution {
  bool isListIntersect(ListNode *l1, ListNode *l2) {
    ListNode *cur1 = l1, *cur2 = l2;
    while (cur1 != cur2) {
      cur1 = cur1 == nullptr ? l2 : cur1->next;
      cur2 = cur2 == nullptr ? l1 : cur2->next;
    }

    return cur1 != nullptr;
  }
};