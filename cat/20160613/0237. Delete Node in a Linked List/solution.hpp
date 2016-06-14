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
  void deleteNode(ListNode* node) {
    if (node == NULL) {
      return;
    }
    ListNode* next = node->next;
    if (next == NULL) {
      return;
    }
    deleteNode(node, next);
  }

private:
  void deleteNode(ListNode *parent, ListNode *current) {
    parent->val = current->val;
    if (current->next == NULL) {
      parent->next = NULL;
      return;
    }
    deleteNode(current, current->next);
  }  
};
