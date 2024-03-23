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
    ListNode* reverseLL(ListNode* head){
        // 2. Reverse Linked List O(n/2) ~ O(n)
        ListNode* second = head;
        ListNode* previous = nullptr;
        while(second != nullptr){
            ListNode* forward = second;
            second = second->next;
            forward->next = previous;
            previous = forward;
        }
        return previous;
    }

    void reorderList(ListNode* head) {
        // Split the linked list in half, reverse the second half, and then merge

        // 1. Get second half O(n)
        ListNode* slow = head;
        ListNode* fast = head->next;
        while((fast != nullptr) && (fast->next != nullptr)){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 3. Merge the two Linked List O(n)
        ListNode* second = reverseLL(slow->next);
        slow->next = nullptr;
        while(second != nullptr){
            ListNode* headNext = head->next;
            ListNode* revNext = second->next;
            head->next = second;
            second->next = headNext;
            head = headNext;
            second = revNext;
        }
    }
};