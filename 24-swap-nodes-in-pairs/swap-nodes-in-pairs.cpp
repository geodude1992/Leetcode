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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while(curr && curr->next){
            // Swap 
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
            // Update next adjacent
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};