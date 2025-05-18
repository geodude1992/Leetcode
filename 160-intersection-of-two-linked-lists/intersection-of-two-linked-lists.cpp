/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Two Pointers Medium Solution
    // T: O(n + n) S: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;    // Pointers at the start of the shorter list
        ListNode* currB = headB;
        while(currA != currB){
            currA = (currA == nullptr) ? headB : currA->next;
            currB = (currB == nullptr) ? headA : currB->next;
        }
        return currA;
    }
};