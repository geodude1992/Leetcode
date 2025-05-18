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
    // Set Solution
    // T: O(n) S: O(n)
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        ListNode* curr = head;
        while(curr){
            if(seen.find(curr) != seen.end()){
                return true;
            }
            seen.insert(curr);
            curr = curr->next;
        }
        return 0;
    }
};