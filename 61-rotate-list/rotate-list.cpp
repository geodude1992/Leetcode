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
    // T: O(n) | S: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* curr = head;
        // Get len
        int lengthOfList = 1;
        while(curr->next != nullptr){
            curr=curr->next;
            lengthOfList++;
        }
        // Create a Cyclic list
        curr->next = head;
        // Reset curr pointer
        curr = head;
        // new head, which is (n - k % n)th node
        for(int i = 0; i < lengthOfList - (k % lengthOfList) - 1; ++i){
            curr = curr->next;
        }
        // Set head to (n-k%n)th node
        head = curr->next;
        // Break the cycle back to a list
        curr->next = nullptr;
        return head;
    }
};