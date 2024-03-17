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
    /*
        The idea is to use three pointers curr, prev, and forward to keep track of nodes to update reverse links.
    Approach 1 - using Iterative Method
        Time complexity: O(N)
        Space complexity: O(1)
        
        nullptr is a keyword denoting universal null pointer value suitable for implicit convetion to any pointer type. 
        NULL is a macro that is implementation defined and as with many macros, its text replacement may not correctly be interpreted, especially in templates. 
        NULL may also fall into unwanted implicit convertions.
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;   // 1
        ListNode* previous = nullptr;
        
        while(current != nullptr){
            ListNode* forward = current;    // 1, 2, 3, 4, 5
            current = current->next;    // 2, 3, 4, 5, null
            forward->next = previous;   // null, 1, 2, 3, 4
            previous = forward;     // 1, 2, 3, 4, 5
        }
        return previous;
    }
};