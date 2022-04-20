/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *x = head, *y = head, *z = head;

        while (k-- > 1) {
            x = x->next;
            y = y->next;
        }

        while (y->next) {
            y = y->next;
            z = z->next;
        }

        int temp = x->val;
        x->val = z->val;
        z->val = temp;

        return head;
    }
};