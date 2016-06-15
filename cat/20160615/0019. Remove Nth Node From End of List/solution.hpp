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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode root(0);
    root.next = head;
    removeNode(&root, head, n);
    return root.next;
  }

private:
  int removeNode(ListNode *parent, ListNode *current, int n) {
    if (current == NULL) {
      return 1;
    }
    int remain = removeNode(current, current->next, n);
    if (remain == n) {
      parent->next = current->next;
    }
    return remain + 1;
  }
};
