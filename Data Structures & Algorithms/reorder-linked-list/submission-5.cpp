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
    void reorderList(ListNode* head) {
        // find midpoint of list
        ListNode *fast = head;
        ListNode *mid = fast;

        while(fast && fast->next) {
            fast = fast->next->next;
            mid = mid->next;
        }

        // reverse second half of list
        ListNode *curr = mid->next;
        ListNode *prev = mid->next = nullptr;

        while(curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // interleave
        ListNode *first = head;
        mid = prev;

        while(mid) {
            ListNode *temp1 = first->next;
            ListNode *temp2 = mid->next;

            first->next = mid;
            mid->next = temp1;
            first = temp1;
            mid = temp2;
        }

        
    }
};
