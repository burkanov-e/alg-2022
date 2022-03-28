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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;

        vector<int> v;

        while (slow != NULL) {
            v.push_back(slow->val);
            slow = slow->next;
        }

        while (head != NULL) {
            int temp = v.back();

            v.pop_back();

            if (head->val != temp) {
                return false;
            }

            head = head->next;
        }
        return true;
    }
};