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
    // Iterative Solution
    // T: O(N) - one pass | S: O(1)
    ListNode* removeElements(ListNode* head, int val) {
        // 1. Eliminate head node(s) if matches target value
        while(head != nullptr && head->val == val) {
            head = head->next;
        }

        ListNode* curr = head;
        // 2. Eliminate inner nodes if matches target value
        while(curr != nullptr && curr->next != nullptr){    
            if(curr->next->val == val){ 
                curr->next = curr->next->next; // next node matchs so next points to next->next, curr stays the same since new curr.next can match target value
            }else{ 
                curr = curr->next; // next doesnt match so curr set to next
            }
        }
        return head;
    }
};