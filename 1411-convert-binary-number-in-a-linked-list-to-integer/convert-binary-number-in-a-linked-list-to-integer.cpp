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
    int getDecimalValue(ListNode* head) {
        vector<int> binary;
        ListNode* curr = head;
        int sum = 0;
        int exp = 0;
        while(curr!=nullptr){
            binary.push_back(curr->val);
            curr=curr->next;
        }
        for(int bit = binary.size()-1; bit >= 0; --bit){
            sum += binary[bit] * pow(2, exp);
            exp++;
        }
        return sum;
    }
};