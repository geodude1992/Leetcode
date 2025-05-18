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
    // Traverse LL and delete in place
    // T: O(n) S: O(1)
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* curr = head;
        ListNode* lastMnode = head;
        while(curr && curr->next){
            // Initialize m and n count for temp
            int mCount = m, nCount = n;
            // Traverse m nodes
            while(mCount != 0 && curr){
                lastMnode = curr;
                curr = curr->next;
                mCount--;
            }
            // Traverse n nodes
            while(nCount != 0 && curr){
                curr = curr->next;
                nCount--;
            }
            // Assign last m node next to curr, deleting n nodes
            lastMnode->next = curr;
        }
        return head;
    }
};