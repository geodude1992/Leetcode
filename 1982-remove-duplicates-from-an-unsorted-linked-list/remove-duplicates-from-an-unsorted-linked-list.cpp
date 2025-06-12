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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        unordered_map<int, int> umap;
        while(curr != nullptr){
            umap[curr->val]++;  // Store node value with their count
            curr = curr->next;
        }

        curr = head;

        while(curr != nullptr){
            if(umap[curr->val] > 1){
                curr = curr->next;
            }else{
                prev->next = curr;
                prev = prev->next;
                curr = curr->next;
            }
        }
        prev->next = curr;
        return dummy.next;
    }
};