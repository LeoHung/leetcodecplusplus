#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* retStart = new ListNode(-1);
    ListNode* retPtr = retStart;
    int next = 0;

    while (true) {
      if (l1 == NULL && l2 == NULL) {
        if (next > 0) {
          retPtr->next = new ListNode(next);
        }
        break;
      }
      ListNode* tmpPtr = NULL;
      if (l1 == NULL) {
        tmpPtr = new ListNode((next + l2->val) % 10);
        next = (next + l2->val) / 10;
        l2 = l2->next;
      } else if (l2 == NULL) {
        tmpPtr = new ListNode((next + l1->val) % 10);
        next = (next + l1->val) / 10;
        l1 = l1->next;
      } else {
        tmpPtr = new ListNode((next + l1->val + l2->val) % 10);
        next = (next + l1->val + l2->val) / 10;
        l2 = l2->next;
        l1 = l1->next;
      }
      retPtr->next = tmpPtr;
      retPtr = retPtr->next;
    }
    return retStart->next;
  }
};

int main(int argc, char **argv) {
  return 0;
}
