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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *ahead = NULL;
        ListNode *curr = head;

        while (curr != nullptr) {
            ahead = curr->next;
            curr->next = prev;

            prev = curr;
            curr = ahead;
        }

        head = prev;
        return head;
    }
};