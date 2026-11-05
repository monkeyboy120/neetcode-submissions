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
            if (!head) return;
    
            ListNode* slow = head;
            ListNode* fast = head->next;
    
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
    
            // slow is mid
    
            // reverse second half
    
            ListNode* curr = slow;
            ListNode* prev = nullptr;
    
            while (curr) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
    
            // prev is head of reversed second half
            ListNode* first = head;
            ListNode* second = prev;
    
            while (first && second) {
                ListNode *temp = first->next;
                ListNode *temp2 = second->next;
                first->next = second;
                second->next = temp;
                first = temp;
                second = temp2;
            }
        }
    };
    