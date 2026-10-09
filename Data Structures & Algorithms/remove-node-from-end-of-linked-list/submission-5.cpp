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
        ListNode* counter = head;

        int length = 0;

        while (counter) {
            counter = counter->next;
            length++;
        }

        int steps = length - n;

        if (steps == 0) {
            return head->next;
        }
        
        ListNode *curr = head;

        for (int i = 0; i < length - 1; ++i) {
            if((i + 1) == steps) { // one before remove
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }

        return head;
    }
};
