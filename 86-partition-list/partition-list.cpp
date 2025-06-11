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
    // Two List Solution
    // T: O(n) | S: O(1)
    ListNode* partition(ListNode* head, int x) {
        ListNode before_head(0), after_head(0); // Create two Node objects with dummy
        ListNode* pBefore = &before_head, * pAfter = &after_head; // create two pointers to node objects

        // Iterate the original LL using head
        while(head){
            // If the node's value pointed to by head is LESSER than x, the node should be part of Before List
            if(head->val < x) pBefore = pBefore->next = head; 
            // Else the node should be part of After List
            else pAfter = pAfter->next = head;

            head = head->next;
        }
        // Combine both List, before and after
        pBefore->next = after_head.next;
        pAfter->next = nullptr;

        // use dot notation is b_head is an object
        return before_head.next;
    }
};