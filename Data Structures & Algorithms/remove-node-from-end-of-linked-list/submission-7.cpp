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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = head;

        // move fast n steps past
        while(n > 0){ 
            fast = fast->next;
            n--;
        }

        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is one before remove node
        slow->next = slow->next->next;

        return dummy.next;

    }
};
