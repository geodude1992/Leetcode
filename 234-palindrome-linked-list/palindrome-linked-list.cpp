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
    // Array 2-ptr Solution
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head != nullptr){
            arr.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = arr.size()-1;
        while(left < right && arr[left] == arr[right]){
            left++;
            right--;
        }
        return left>=right;
    }
};